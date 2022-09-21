/* 
    Adaptor class Example
    1) we Have Person Service class  which is having IPseon inteface to print details about
        the Person
    2) But French people is also having the french person class but they can't use it directly 
        because in french name=> nom, age => agee and so on
    3) we have created a French Adaptor which is implementing the Iperson interface.
        now french people can use the person service class for person details using french adaptor
*/

#include<iostream>
using  namespace std;

class IPerson
{
    public:
        virtual string personName() = 0;
        virtual string personAge() = 0;
        virtual string personPostalCode() = 0;
};
class IndianPerson : public IPerson
{
    private:
        string person_name;
        string person_age;
        string person_postal_address_code;
    public:
        IndianPerson(string,string,string);
        string personName();
        string personAge();
        string personPostalCode();
};

IndianPerson::IndianPerson(string person_name, string person_age, string person_postal_address_code)
{
    this->person_name = person_name;
    this->person_age = person_age;
    this->person_postal_address_code = person_postal_address_code;
}
string IndianPerson::personName()
{
    return this->person_name;
}
string IndianPerson::personAge()
{
    return this->person_age;
}
string IndianPerson::personPostalCode()
{
    return this->person_postal_address_code;
}
//============================================

class IFrenchPerson
{
    public:
        virtual string la_personneNom() = 0;
        virtual string la_personneAgee() = 0;
        virtual string la_personneZipCode() = 0;
};
class FrenchPerson : public IFrenchPerson
{
    private:
        string la_personne_nom;
        string la_personne_agee;
        string la_personne_zip_code;
    public:
        FrenchPerson(string,string,string);
        string la_personneNom();
        string la_personneAgee();
        string la_personneZipCode();
};
FrenchPerson::FrenchPerson(string la_personne_nom, string la_personne_agee, string la_personne_zip_code)
{
    this->la_personne_nom = la_personne_nom;
    this->la_personne_agee = la_personne_agee;
    this->la_personne_zip_code = la_personne_zip_code;
}
string FrenchPerson::la_personneNom()
{
    return this->la_personne_nom;
}
string FrenchPerson::la_personneAgee()
{
    return this->la_personne_agee;
}
string FrenchPerson::la_personneZipCode()
{
    return this->la_personne_zip_code;
}

//---------------Service class-------------------

class PersonService
{
    public:
    void PrintDetails(IPerson *person)
    {
        cout<<"Person details :-  Name "<<person->personName()<<", Age := "<<person->personAge()
            <<", ZipCode := "<<person->personPostalCode()<<endl;
    }
};

//================= Adaptor interface ================

class FrenchPersonAdaptor : public IPerson
{
    private:
        FrenchPerson *fp;
    public:
        FrenchPersonAdaptor(FrenchPerson*);
        string personName();
        string personAge();
        string personPostalCode();
        ~FrenchPersonAdaptor();
};

FrenchPersonAdaptor::FrenchPersonAdaptor(FrenchPerson *frenchperson)
{
    this->fp = frenchperson;
}
string FrenchPersonAdaptor::personName()
{
    return this->fp->la_personneNom();
}
string FrenchPersonAdaptor::personAge()
{
    return this->fp->la_personneAgee();
}
string FrenchPersonAdaptor::personPostalCode()
{
    return this->fp->la_personneZipCode();
}
FrenchPersonAdaptor::~FrenchPersonAdaptor()
{
    delete this->fp;
}
//==================client code =============

int main()
{
    PersonService *person_service = new PersonService();
    IndianPerson *person = new IndianPerson("Kunal", "26", "802212");
    FrenchPerson *f_person = new FrenchPerson("Fabio", "19", "75004");

    person_service->PrintDetails(person);
    person_service->PrintDetails(new FrenchPersonAdaptor(f_person));
    return 0;
}