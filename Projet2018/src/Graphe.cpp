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

}

void Graphe::affichage(BITMAP* buffer, BITMAP* barre, BITMAP* fleche)
{
    for (unsigned int i(0); i <Getaretes().size(); ++i)
    {
        line(buffer, Getaretes()[i]->Getdepart()->GetCd_x() + Getaretes()[i]->Getdepart()->GetImg()->w/2, Getaretes()[i]->Getdepart()->GetCd_y() + Getaretes()[i]->Getdepart()->GetImg()->h/2, Getaretes()[i]->Getarrive()->GetCd_x() + Getaretes()[i]->Getarrive()->GetImg()->w/2, Getaretes()[i]->Getarrive()->GetCd_y() + Getaretes()[i]->Getarrive()->GetImg()->h/2, makecol(255,0,0));

        //stretch_sprite(buffer, fleche, Getaretes()[i]->Getdepart()->GetCd_x(), Getaretes()[i]->Getdepart()->GetCd_y(), Getaretes()[i]->Getdepart()->GetImg()->w, Getaretes()[i]->Getdepart()->GetImg()->h/*, Getaretes()[i]->Getarrive()->GetCd_x(), Getaretes()[i]->Getarrive()->GetCd_y(), Getaretes()[i]->Getarrive()->GetImg()->w, Getaretes()[i]->Getarrive()->GetImg()->h*/);
    }

    for (unsigned int i(0); i<Getsommets().size(); ++i)
    {
        blit(getSommet(i)->GetImg(), buffer, 0, 0, (getSommet(i))->GetCd_x(), (getSommet(i))->GetCd_y(), getSommet(i)->GetImg()->w, getSommet(i)->GetImg()->h);
    }

    blit(barre, buffer,0,0,0,600 - barre->h, barre->w, barre->h);
    outils(buffer);
    blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    clear_bitmap(buffer);
}

void Graphe::outils(BITMAP* buffer)
{
    if (is_mouse(745, 50, 5, 50))
    {
        rectfill(buffer, 743, 3, 797, 57, makecol(0,250,0));

        if(mouse_b&1)
            ajouterArete(buffer);
    }

    if (is_mouse(745, 50, 65, 50))
    {
        rectfill(buffer, 743, 63, 797, 117, makecol(255,0,0));

        if(mouse_b&1)
        {
            suppSommet();
        }
    }

    if (is_mouse(745, 50, 125, 50))
    {
        rectfill(buffer, 743, 123, 797, 177, makecol(255,0,255));

        if(mouse_b&1)
        {
            ajouSommet();
        }
    }


    rectfill(buffer, 745, 5, 795, 55, makecol(0,250,0));

    rectfill(buffer, 745, 65, 795, 115, makecol(255, 0, 0));

    rectfill(buffer, 745, 125, 795, 175, makecol(255,0,255));


}

void Graphe::ajouterArete(BITMAP* buffer)
{
    Arete* a;
    Sommet* s;

    int prev_mouse_b;
    int now_mouse_b;
    a= new Arete;
    s= new Sommet;

    std::vector<Arete*> tmp;

    tmp = Getaretes();

    while(s->getNomImg() == "")
    {

        prev_mouse_b = now_mouse_b;
        now_mouse_b = mouse_b&1;
        for (unsigned int i(0); i<Getsommets().size(); ++i)
        {
            if(is_sommmet(i))
            {
                if (!prev_mouse_b && now_mouse_b)
                {
                    s = Getsommets()[i];
                    a->Setdepart(s);
                }
            }
        }
    }

    rect(screen, a->Getdepart()->GetCd_x()-2, a->Getdepart()->GetCd_y()-2, a->Getdepart()->GetImg()->w +a->Getdepart()->GetCd_x()+1,a->Getdepart()->GetImg()->h + a->Getdepart()->GetCd_y()+1, makecol(255,0,0));

    s= new Sommet;

    while(s->getNomImg() == "")
    {
        prev_mouse_b = now_mouse_b;
        now_mouse_b = mouse_b&1;
        for (unsigned int i(0); i<Getsommets().size(); ++i)
        {
            if(is_sommmet(i))
            {
                if (!prev_mouse_b && now_mouse_b)
                {
                    s = Getsommets()[i];
                    a->Setarrive(s);
                }
            }
        }
    }

    tmp.push_back(a);

    Setaretes(tmp);
    std::cout << "ajou reussi" << std::endl;
}

void Graphe::ajouSommet()
{
    Sommet* s;
    int prev_mouse_b;
    int now_mouse_b;

    s = new Sommet;

    std::vector<Sommet*> som(Getsommets());

    while(s->getNomImg() == "")
    {
        prev_mouse_b = now_mouse_b;
        now_mouse_b = mouse_b&1;

        if (!prev_mouse_b && now_mouse_b)
        {
            //s->SetCd_x(500)
            s = new Sommet(500, 400, 12, 40, "Images/laminaire.jpg");
            som.push_back(s);
        }
    }

    Setsommets(som);
}

void Graphe::suppSommet()
{
    int prev_mouse_b;
    int now_mouse_b;

    std::vector<Sommet*> tmp(Getsommets());
    std::vector<Arete*> temp(Getaretes());

    bool stop(false);

    if(tmp.size() > 0)
    {
        while(tmp.size()+1 != Getsommets().size())
        {
            prev_mouse_b = now_mouse_b;
            now_mouse_b = mouse_b&1;

            for(unsigned int i(0); i < tmp.size() ; ++i)
            {
                if(i == 0)
                   stop = false;

                if(is_sommmet(i))
                {
                    if (!prev_mouse_b && now_mouse_b && !stop)
                    {
                        for(unsigned int j(0); j < temp.size(); ++j)
                        {
                            if(tmp[i] == temp[j]->Getdepart() || tmp[i] == temp[j]->Getarrive())
                            {
                                temp.erase(temp.begin() + j);
                                --j;
                            }
                        }

                        tmp.erase(tmp.begin()+i);
                        stop = true;
                    }
                }
            }
        }
    }

    Setsommets(tmp);
    Setaretes(temp);
}



void Graphe::update(BITMAP* buffer, BITMAP* barre, BITMAP* fleche)
{
    for(int i(Getsommets().size()-1); i >= 0 ; --i)
    {
        if(is_sommmet(i))
        {
            if(mouse_b&1)
            {
                while(mouse_b&1)
                {
                    rectfill(buffer, Getsommets()[i]->GetCd_x()-2, Getsommets()[i]->GetCd_y()-2, Getsommets()[i]->GetImg()->w +Getsommets()[i]->GetCd_x()+1,Getsommets()[i]->GetImg()->h + Getsommets()[i]->GetCd_y()+1, makecol(0,255,0));

                    Getsommets()[i]->SetCd_x(mouse_x-Getsommets()[i]->GetImg()->w/2);
                    Getsommets()[i]->SetCd_y(mouse_y-Getsommets()[i]->GetImg()->h/2);

                    affichage(buffer, barre, fleche);
                }
            }
        }
    }
}

bool Graphe::is_mouse(int x, int weight, int y, int height)
{
    return     mouse_x >= x && mouse_x <= x + weight  &&  mouse_y >= y && mouse_y <= y + height;
}

bool Graphe::is_sommmet(int i)
{
    return     mouse_x >= Getsommets()[i]->GetCd_x() && mouse_x <= Getsommets()[i]->GetCd_x() + Getsommets()[i]->GetImg()->w
               &&  mouse_y >= Getsommets()[i]->GetCd_y() && mouse_y <= Getsommets()[i]->GetCd_y() + Getsommets()[i]->GetImg()->h;
}
