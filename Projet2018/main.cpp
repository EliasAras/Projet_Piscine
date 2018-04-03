

#include "Graphe.h"

int main()
{
    std::cout << "Hello world!" << std::endl;

    srand(time(NULL));
    set_uformat(U_ASCII);
    allegro_init();
    install_timer();
    install_keyboard();
    install_mouse();

    register_png_file_type();
    jpgalleg_init();
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("Probleme mode GFX");
        allegro_exit();

        exit(EXIT_FAILURE);
    }

    BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);

    BITMAP* barre;
    barre = load_bitmap("images/tabgraph.png", NULL);
    if(!barre)
    {
        allegro_message("pas pu trouver barre.png");
        exit(EXIT_FAILURE);
    }
    blit(barre, screen,0,0,0,600 - barre->h, barre->w, barre->h);

    Graphe g("Sommets.txt");
    show_mouse(screen);
    for (unsigned int i(0); i<g.Getsommets().size(); ++i)
    {
//        std::cout << "test" << i << std::endl;
//        if (i == 0)g.affichage();
        blit(g.getSommet(i)->GetImg(), buffer, 0, 0, (g.getSommet(i))->GetCd_x(), (g.getSommet(i))->GetCd_y(), g.getSommet(i)->GetImg()->w, g.getSommet(i)->GetImg()->h);
    }

    while (!key[KEY_ESC])
    {
        blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }

    destroy_bitmap(buffer);

    return 0;
}
END_OF_MAIN();

