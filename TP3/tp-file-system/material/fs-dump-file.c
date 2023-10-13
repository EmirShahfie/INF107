#include <assert.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage : %s <file-to-dump>>\n", argv[0]);
    exit(1);
  }

  /* Open file to read it.
   */

  uint32_t value;
  int nbyte;
  int offset = 0;

  /* Read 4 unsigned integers of 32 bits. Print the offset
  in the file and the 4 unsigned integers
   */
  while (1) {
    /* Print offset in the file.
     */
    printf("%08x :", offset);

    /* Print 4 unsigned integers of 32 bits.
     */
    for (int i = 0; i < 4; i++) {
      /* Read a unsigned integer of 32 bits. Check the result.
       */

      /* Exit when we reach end of file or cannot read a value.
       */
      printf(" %08x", value);
    }
    printf("\n");
    offset = offset + sizeof(value);

    /* Exit when we reach end of file or cannot read a value.
     */
  }
  
  /* Close file before terminating. Done by default.
   */
}
