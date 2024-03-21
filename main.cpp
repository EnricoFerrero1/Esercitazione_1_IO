#include <iostream>
#include <fstream>
#include <iomanip>

double mappavalore(double x) //funzione che mappa i valori in [1,5] in [-1,2]
{
    return (3./4.)*x-(7./4.);
}


int main()
{
    //nomino e apro i file
    std::string fileinput = "data.csv";
    std::string fileoutput = "result.csv";
    std::ifstream ifs(fileinput);
    std::ofstream ofs(fileoutput);

    if(ifs.is_open() && ofs.is_open())
    {
        ofs << "#N mean\n";
        ofs << std::setprecision(16); //imposto precisione di macchina
        ofs.setf(std::ios_base::scientific); //imposto formato scientifico
        double somma=0;
        int i=0;
        while (!ifs.eof()) //applico mappavalore e calcolo la media ad ogni passo
        {
            i++;
            double n;
            ifs >> n;
            double t=mappavalore(n);
            somma += t;
            ofs << i << " " << somma/i << "\n";
        }
    }

   else //verifico la presenza di errori
    {
        std::cerr<<"errore nella lettura di " << fileinput << " o nella creazione di " << fileoutput << "\n";
        return 1;
    }
    //chiudo i file
    ofs.close();
    ifs.close();

    return 0;
}
