

int main()
{
    char *names[] = { "John", "Mona", "Lisa", "Frank" };
    int i=0;
    for (i = 0; i < 4; ++i) {
        char *pos = names[i];
        while (*pos != '\0') {
            printf("%c", *(pos++));
        }
        printf("\n");
    }
}
