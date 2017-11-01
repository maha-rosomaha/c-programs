#include <string.h>
#include <stdio.h>
#include <stdlib.h>

enum {N = 5};

void
roll_left(FILE *fp, long ch_start, long dif_len)
{
    char buf[N], tmp[N];
    long cur, len, nxt;
    while (dif_len > N) {
        fseek(fp, ch_start, SEEK_SET);
        cur = ftell(fp);
        fread(buf, sizeof(char), N, fp);
        while ((len = fread(tmp, sizeof(char), N, fp)) != 0) {
            nxt = ftell(fp);
            fseek(fp, cur, SEEK_SET);
            fwrite(tmp, sizeof(char), len, fp);
            cur = ftell(fp);
            fseek(fp, nxt, SEEK_SET);
        }
        fseek(fp, cur, SEEK_SET);
        fwrite(buf, sizeof(char), N, fp);
        dif_len -= N;
        fseek(fp, ch_start, SEEK_SET);
    }
    if (dif_len != 0) {
        fseek(fp, ch_start, SEEK_SET);
        cur = ftell(fp);
        fread(buf, sizeof(char), dif_len, fp);
        while ((len = fread(tmp, sizeof(char), dif_len, fp)) != 0) {
            nxt = ftell(fp);
            fseek(fp, cur, SEEK_SET);
            fwrite(tmp, sizeof(char), dif_len, fp);
            cur = ftell(fp);
            fseek(fp, nxt, SEEK_SET);
        }
        fseek(fp, cur, SEEK_SET);
        fwrite(buf, sizeof(char), dif_len, fp);
    }
}

int
main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r+");
    fseek(fp, 0, SEEK_END);
    roll_left(fp, 5, 7);
    fclose(fp);
    return 0;
}
