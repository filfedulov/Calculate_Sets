#include "Operations.h"
#include"Menu.h"


int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru");

    Operations object_o;
    object_o.create_sets();
    object_o.cout_sets();
    object_o.negation();
    object_o.intersection_sets();
    object_o.uinion_sets();
    object_o.difference_sets();
    object_o.simetricDifference_sets();
    //Menu menu;
    //menu.choice_menu();

    return 0;
}

