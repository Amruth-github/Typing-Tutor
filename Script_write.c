#include "proj.h"

void script_write()
{
    FILE* fp = fopen("script_1.txt", "wb");
    fprintf(fp, "Mr and Mrs Dursley, of number four, Privet Drive, were proud to say that they were perfectly normal\nthank you very much. They were the last people you'd expect to be\ninvolved in anything strange or mysterious, because they just\ndidn't hold with such nonsense.\n");
    fclose(fp);
}
void script_write_1()
{
    FILE* fp = fopen("script_2.txt", "wb");
    fprintf(fp, "The villagers of Little Hangleton still called it \"the Riddle House,\" even though it\nhad been many years since the Riddle family had lived there. It stood on a hill\noverlooking the village, some of its windows boarded, tiles missing from its roof,\nand ivy spreading unchecked over its face");
    fclose(fp);
}
void script_write_2()
{
    FILE* fp = fopen("script_3.txt", "wb");
    fprintf(fp, "Harry finished writing about Wendelin the Weird and paused to listen again. The silence in the\ndark house was broken only by the distant, grunting snores of his enormous cousin, Dudley. It\nmust be very late, Harry thought. His eyes were itching with tiredness. Perhaps he'd finish this\nessay tomorrow night");
    fclose(fp);
}