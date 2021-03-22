#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>

struct Car {
    std::string getRendszam() const { return this->Rendszam; }

    std::string Rendszam;
    int loero;
    bool savtarto;

    friend std::ostream& operator << (std::ostream& s, const Car& c) {
        return s << c.getRendszam() << " " << c.loero << " " << c.savtarto;
    }

    friend std::istream& operator >> (std::istream& s, Car& c) {
        int n;
        bool value;
        s >> c.Rendszam >> c.loero >> c.savtarto;

        std::size_t found = c.Rendszam.find_first_of("[]/!*{}$");

        if (found != std::string::npos) {
            c.Rendszam = "AAA-000";
            throw "HIBA";
        }

        
    }
};

/*
struct B {
    B(initializer_list<B> lst);
    int n1;
    int n2;
    int n3;
};*/

//B b1 {10, 20, 30}
int addNumbers(int a, int b)
{
    return a + b;
}

int multiplyNumbers(int a, int b)
{
    return a * b;
}



void genBin()
{
    std::ofstream outputfile;
    int a[20];

    for (int i = 0; i < 20; ++i)
        a[i] = i;


    outputfile.open("gen.bin",std::ios::binary);
    outputfile.write(reinterpret_cast<char*>(a), 4 * 20);
    outputfile.close();
}

void demoSeekFile()
{
    int number;
    std::ifstream inputfile("gen.bin");

    inputfile.seekg(3*4, inputfile.beg);
    inputfile.read(reinterpret_cast<char*>(&number), 4);
    std::cout << number << std::endl;

    inputfile.close();
}

void demoCarIO()
{
    Car c,c2;
    c.Rendszam = "ADF-569";
    c.loero = 230;
    c.savtarto = false;

    std::ofstream outputfile("out.txt");
    outputfile << c;
    outputfile.close();

    std::ifstream inputfile("out.txt");
    inputfile >> c2;
    std::cout << c2;
    inputfile.close();
}

/*
class sajat_muvelet :
{
    sajat_muvelet() = default;
    /*
    */

  //  sajat_muvelet operator () {}

//};

int main()
{
    
    genBin();
    demoSeekFile();
    //demoCarIO();
    
    std::ifstream inputfile("input.txt");

    //fájlméret lekérdezése
    inputfile.seekg(0,inputfile.end);
    std::cout << inputfile.tellg() << std::endl;
    inputfile.seekg(0, inputfile.beg);

    inputfile.close();

    int n;
    inputfile.open("input.txt");

    inputfile.seekg(5, inputfile.beg);
    inputfile >> n;
    std::cout << n << std::endl;

    inputfile >> n;
    std::cout << n << std::endl;

    inputfile.seekg(3, inputfile.beg);

    inputfile >> n;
    std::cout << n << std::endl;

    inputfile.close();
    
    /*int a;
    int b=0;
    int c = b;

    [=](int n) { std::cout << n << std::endl; };
    [](int a, int b) -> int {return a + b; };
    [](int a, int b) {return a - b; };
    [](int a, int b) {return a * b; };
    [](int a, int b) {return a / b; };
    */
    /*int a;
    double b;
    char c=0;

    auto n = c;


    const int n = 3;
    n = 5;

   std::vector<int> myvector;
   myvector.push_back(10);
   myvector.push_back(20);
   myvector.push_back(30);

    std::for_each(myvector.begin(), myvector.end(), [](int i){std::cout << i << std::endl; });
    
    
    for (int i = 0; i < myvector.size(); ++i)
        std::cout << myvector.at(i) << std::endl;
    std::cout << '\n';
    */
    // the type of a closure cannot be named, but can be inferred with auto
    // since C++14, lambda could own default arguments
    auto func1 = [](int i = 6) { return i + 4; };
    std::cout << "func1: " << func1(5) << '\n';
   
    // like all callable objects, closures can be captured in std::function
    // (this may incur unnecessary overhead)
    std::function<int(int)> func2 = [](int i) { return i + 4; };
    std::cout << "func2: " << func2(6) << '\n';
	return 0;
}