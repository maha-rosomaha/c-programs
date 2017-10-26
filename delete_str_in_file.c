#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
    FILE *fp;
    int c, i, j, flag;
    if (argc < 2) {
        fprintf(stderr, "not enough arguements");
        return 1;
    }
    fp = fopen(argv[1], "r+");
    if (!fp) {
        perror("fopen");
        return 1;
    }
    i = ftell(fp);
    while ((c = fgetc(fp)) != EOF) {
        flag = (c == '#');
        while (c != '\n') {
            c = fgetc(fp);
        }
        if (flag) {
            break;
        }
        i = ftell(fp);
    }
/*    j = ftell(fp);*/
    while ((c = fgetc(fp)) != EOF) {
        j = ftell(fp);
        if(fseek(fp, i, SEEK_SET) == -1) {
            perror("fseek");
            return 1;
        }
        fputc(c, fp);
        i = ftell(fp);
        fseek(fp, j, SEEK_SET);
    }
    fclose(fp);
/* change size of file*/
    truncate(argv[1], i-1);
    return 0;
}
