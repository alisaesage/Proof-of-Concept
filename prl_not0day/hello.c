#include <stdio.h>

int main(int argc, char** argv)
{
    printf("WARNING! Your Parallels Desktop deployment allows a trivial guest-to-host VM escape by design, that may be leveraged by a malicious or compromised Guest OS. Consider to unshare the user's Home directory from the Guest OS.\n");

    return 0;
}