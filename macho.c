#include <string.h>
#include <sys/mman.h>

char payload[1024] = "PAYLOAD:";

int main() {
    void *ptr = mmap(0, sizeof(payload), PROT_EXEC | PROT_WRITE | PROT_READ, MAP_ANON | MAP_PRIVATE, -1, 0);

    if (ptr == MAP_FAILED)
        return 1;

    memcpy(ptr, payload, sizeof(payload));
    int (*sc)() = ptr;
    sc();

    return 0;
}
