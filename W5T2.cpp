#include "W5T2.h"

void Beer::erase()
{
    delete this->brand;
}

void Beer::copy(const Beer &other)
{
    setBrand(other.brand);
    setSize(other.size);
}

Beer::Beer()
{
    setBrand("");
    setSize(0);
}
Beer::Beer(const char *brand, const int size)
{
    setBrand(brand);
    setSize(size);
}
Beer::Beer(const Beer &other)
{
    this->copy(other);
}
Beer &Beer::operator=(const Beer &other)
{
    if (this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}
Beer ::~Beer()
{
    erase();
}

const char *Beer ::getBrand() const
{
    return this->brand;
}
int Beer ::getSize() const
{
    return this->size;
}

void Beer::setBrand(const char *other)
{
    delete[] this->brand;
    this->brand = new char[strlen(other) + 1];
    strcpy(this->brand, other);
}
void Beer::setSize(int other)
{
    this->size = other;
}

void Beer::add(Beer &beer, int size)
{

    char *tempBrand = new char[strlen(this->brand) + strlen(beer.brand)];
    strcpy(tempBrand, this->brand);
    strcat(tempBrand, "&");
    strcat(tempBrand, beer.brand);
    delete[] this->brand;
    this->brand = new char[strlen(tempBrand) + 1];
    strcpy(brand, tempBrand);
    delete[] tempBrand;

    this->size += size;
    beer.setSize(beer.size - size);
}
bool Beer::check(const char *brand)
{
    return strstr(this->brand, brand) != NULL;
}
void Beer::print()
{
    cout << "The brand of the beer is " << this->brand << " and it's size is " << this->size << "ml" << endl;
}
int main()
{
    Beer beer1("Stella Artois", 500);
    Beer beer2("Becks", 500);
    beer1.print();
    beer1.add(beer2, 250);
    beer1.print();
    beer2.print();
    if (beer1.check("Becks"))
    {
        cout << "It's inside" << endl;
    }
    else
    {
        cout << "It's not inside" << endl;
    }
}
