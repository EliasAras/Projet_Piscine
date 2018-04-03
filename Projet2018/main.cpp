#include <iostream>
#include <allegro.h>
#include <png.h>
#include <loadpng.h>
#include <jpgalleg.h>
#include <ctime>

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

    show_mouse(screen);

    return 0;
}
END_OF_MAIN();

