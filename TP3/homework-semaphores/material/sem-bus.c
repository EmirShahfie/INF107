#include <assert.h>
#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>


#define shared_variable_seats_name "shared_variable_seats.var"
#define shared_variable_passengers_name "shared_variable_passengers.var"

int max_passengers, max_seats;
int n_passengers, n_seats;


void execute_passenger();
void execute_driver();

// Read an integer from a file. This intends to simulate a read operation on a
// shared integer variable of name name.
int read_shared_var(char *name);

// Write an integer into a file. This intends to simulate a write operation on a
// shared integer variable of name name.
void write_shared_var(char *name, int value);

// Set up a handshake with two semaphores one assigned to the process itself the
// other to the partner.
void rendez_vous(sem_t *i_arrive, sem_t *u_arrive);

int main(int argc, char **argv) {

  if (argc != 3) {
    printf("Usage : %s <max_seats> <max_passengers>\n", argv[0]);
    exit(1);
  }
  max_seats = strtol(argv[1], NULL, 10);
  max_passengers = strtol(argv[2], NULL, 10);
  write_shared_var(shared_variable_seats_name, max_seats);
  write_shared_var(shared_variable_passengers_name, 0);


  for (n_passengers = 0; n_passengers < max_passengers; n_passengers++)
    if (fork() == 0)
      execute_passenger();

  execute_driver();
}

void execute_driver() {
  sleep(1);
  printf("Bus arrives at station\n");

  n_seats = read_shared_var(shared_variable_seats_name);
  n_passengers = read_shared_var(shared_variable_passengers_name);
  if (n_seats > 0 && n_passengers > 0) {
    n_seats--;
    n_passengers--;
    write_shared_var(shared_variable_seats_name, n_seats);
    write_shared_var(shared_variable_passengers_name, n_passengers);


    printf("Driver boarding new passenger\n");


    printf("Driver ready to leave\n");


    printf("Bus leaves station\n");
  } else {

    printf("Bus leaves station (empty)\n");
  }
  exit(0);
}

void execute_passenger() {
  int id;
  int new_passenger_boarding;


  n_passengers = read_shared_var(shared_variable_passengers_name);
  n_passengers++;
  id = n_passengers;
  write_shared_var(shared_variable_passengers_name, n_passengers);
  printf("Passenger %d arrives at station\n", id);


  n_seats = read_shared_var(shared_variable_seats_name);
  n_passengers = read_shared_var(shared_variable_passengers_name);
  new_passenger_boarding = (n_seats > 0 && n_passengers > 0);
  n_seats--;
  n_passengers--;
  write_shared_var(shared_variable_seats_name, n_seats);
  write_shared_var(shared_variable_passengers_name, n_passengers);
  printf("Passenger %d boards the bus\n", id);


  if (new_passenger_boarding) {

    printf("Passenger %d boarding next passenger\n", id);
  } else {
    printf("Passenger %d ask driver to leave\n", id);

  }
  exit(0);
}

// Set up a handshake with two semaphores one assigned to the process itself the
// other to the partner.
void rendez_vous(sem_t *i_arrive, sem_t *u_arrive) {
}

// Generate a random integer value between first and last
int value_between(int first, int last) {
  int length = last - first + 1;
  return first + (int)(random() % length);
}

// Read an integer from a file. This intends to simulate a read operation on a
// shared integer variable of name name.
int read_shared_var(char *name) {
  int value;
  int fd = open(name, O_RDWR);
  int rv;
  assert(fd > 0);
  rv = read(fd, &value, sizeof(int));
  assert(rv == sizeof(int));
  close(fd);
  return value;
}

// Write an integer into a file. This intends to simulate a write operation on a
// shared integer variable of name name.
void write_shared_var(char *name, int value) {
  int fd = open(name, O_CREAT | O_RDWR, 0644);
  int rv;
  assert(fd > 0);
  rv = write(fd, &value, sizeof(int));
  assert(rv == sizeof(int));
  close(fd);
}
