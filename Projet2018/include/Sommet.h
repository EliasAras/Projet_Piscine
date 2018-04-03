#ifndef SOMMET_H
#define SOMMET_H
#include <allegro.h>

class Sommet
{
    public:
        Sommet();
        ~Sommet();

        int GetCd_x() { return m_cd_x; }
        int GetCd_y() { return m_cd_y; }
        int GetNum() { return m_num; }
        int GetPoids() { return m_poids; }
        BITMAP* GetImg() { return m_img; }

        void SetCd_x(int val) { m_cd_x = val; }
        void SetCd_y(int val) { m_cd_y = val; }
        void SetNum(int val) { m_num = val; }
        void SetPoids(int val) { m_poids = val; }
        void SetImg(BITMAP* val) { m_img = val; }

    private:
        int m_cd_x;
        int m_cd_y;
        int m_num;
        int m_poids;
        BITMAP* m_img;
};

#endif // SOMMET_H
