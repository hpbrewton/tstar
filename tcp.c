#include<stdio.h>

typedef struct __attribute__((packed)) {
    short src_port;
    short dst_port;
    int seq_num;
    int ack_num;
    char data_offset;
    char flags;
    short window;
    short checksum;
    short urgent_pointer;
} packet_t; 

void
setup(packet_t *pack, char flags, int seq_num, int ack_num) {
    pack->flags = flags;
    pack->seq_num = seq_num;
    pack->ack_num = ack_num;

    short res = 
}

int main(int argc, char *argv[]) {
    printf("%lu\n", sizeof(packet_t));
}