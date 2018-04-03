#ifndef SOMMET_H
#define SOMMET_H
#include <allegro.h>

class Sommet
{
    public:
        Sommet();
        ~Sommet();

        int Getcd_x() { return m_cd_x; }
        int Getcd_y() { return m_cd_y; }
        int Getnum() { return m_num; }
        int Getpoids() { return m_poids; }
        BITMAP* Getimg() { return m_img; }

        void Setcd_x(int val) { m_cd_x = val; }
        void Setcd_y(int val) { m_cd_y = val; }
        void Setimg(BITMAP* val) { m_img = val; }
        void Setnum(int val) { m_num = val; }
        void Setpoids(int val) { m_poids = val; }

    private:
        int m_cd_x;
        int m_cd_y;
        BITMAP* m_img;
        int m_num;
        int m_poids;
};

#endif // SOMMET_H
