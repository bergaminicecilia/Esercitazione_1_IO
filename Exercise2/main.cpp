# include <iostream>
# include <fstream>
# include <iomanip>

// funzione che mappa i punti appartenenti a [1,5] nell'intervallo [-1,2]
double mappedValues(double val, int a, int b, int c, int d)
{
    double valmapped = c + (val-a)*(d-c)/(b-a);
    return valmapped;
}

// funzione che calcola la media
double meanFunction(double sum, int num)
{
    double mean = sum/num;
    return mean;
}


int main()
{
    int a = 1;
    int b = 5;
    int c = -1;
    int d = 2;
    std::string nameFileInput = "data.csv";
    std::ifstream ifstr(nameFileInput);
    std::string nameFileOutput = "result.csv";
    std::ofstream ofs(nameFileOutput);

    if (ifstr.fail())
    {
        std::cerr << "File does not exist" << std::endl;
        return 1;
    }


    double sum = 0;
    int j = 0;
    double val;
    ofs << "# N Mean" << std::endl;

    if(ifstr.is_open()){
        while(ifstr >> val)
        {
            double vmapped = mappedValues(val, a, b, c, d);
            sum += vmapped;
            j += 1;
            double mean = meanFunction(sum,j);
            ofs << j << " " << std::fixed << std::setprecision(16) << std::scientific << mean << std::endl;
        }
    }
    ifstr.close();
    ofs.close();

    return 0;
}
