#include "Graphe.h"

Graphe::Graphe(std::string nom_fichier)
{
    int cd_x, cd_y, num, poids;
//    Sommet* s;
    std::string nom_img;

    std::ifstream fichier(nom_fichier, std::ios::in);
    if (!fichier)
    {
        std::cout << nom_fichier << " ne peut pas etre ouvert!" << std::endl;
        return;
    }
    else
    {
        fichier >> m_ordre;
        for (int i(0); i<m_ordre; ++i)
        {

            fichier >> nom_img;
            fichier >> cd_x >> cd_y >> num >> poids;

//            s = new Sommet()
            ajouterSommet(new Sommet(cd_x, cd_y, num, poids, nom_img));
        }
    }
}

Graphe::~Graphe()
{
    //dtor
}

void Graphe::affichage()
{
    for (unsigned int i = 0; i<Getsommets().size() ; ++i)
    {
        std::cout << getSommet(i)->GetCd_x() << std::endl;
        std::cout << getSommet(i)->GetCd_y() << std::endl;
        std::cout << getSommet(i)->GetNum() << std::endl;
        std::cout << getSommet(i)->GetPoids() << std::endl;
        std::cout << getSommet(i)->getNomImg() << std::endl << std::endl;
//        std::cout << getSommet(i).GetCd_x() << std::endl;
    }
}

void Graphe::update()
{
    for(int i(0); i < Getsommets().size(); ++i)
    {
        if(is_mouse(Getsommets()[i]->GetCd_x(), Getsommets()[i]->GetImg()->w, Getsommets()[i]->GetCd_y(), Getsommets()[i]->GetImg()->h))
        {
            rect(screen, Getsommets()[i]->GetCd_x(),Getsommets()[i]->GetImg()->w, Getsommets()[i]->GetCd_y(), Getsommets()[i]->GetImg()->h, makecol(0,255,0));
        }
    }
}

bool Graphe::is_mouse(int x, int weight, int y, int height)
{
    return     mouse_x >= x && mouse_x <= x + weight
               &&  mouse_y >= y && mouse_y <= y + height;
}
