#include "Project1_pch.h"
#pragma hdrstop

#include <exception>

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

template< class T >
struct TDynArr
{
    typedef T Type;
    struct out_of_range{};      //exceptions
    struct out_of_capacity{};
    int     _capacity;  // buffer size
    int     _size;      //used
    Type    _ar[0];



    const Type& operator[](int i) const
    {
        return _ar[i];
    }
    Type& operator[](int i)
    {
        return _ar[i];
    }
    void check_range(int i)
    {
        if( i < 0 || i >= _size )
            throw out_of_range();
    }
    const Type& at(int i) const
    {
        check_range(i);
        return _ar[i];
    }
    Type& at(int i)
    {
        check_range(i);
        return _ar[i];
    }
    int size() const
    {
        return _size;
    }
    int capacity() const
    {
        return _capacity;
    }
    void push_back(const Type& value)
    {
        if( _size == _capacity )
        {
            throw out_of_capacity();
        }
        _ar[_size++] = value;
    }
    TDynArr& operator+=(const Type& value)
    {
        push_back(value);
        return *this;
    }

};



template <class T>
TDynArr<T>* TDynArr_Create(int capacity)
{
    int ts = sizeof(TDynArr<int>) +  sizeof(int)*capacity;
    TDynArr<int>* r = (TDynArr<int>*) malloc( ts );
    r->_capacity = capacity;
    r->_size = 0;
    return r;
}

template <class T>
void TDynArr_Free(TDynArr<T>* &arr)
{
    free(arr);
    arr = 0;
}

struct MyStruct
{
    int i;
};


void __fastcall TForm1::Button1Click(TObject *Sender)
{
//

    Memo1->Lines->Add( "sizeof(DynArr<int>" + IntToStr(sizeof(TDynArr<int>)) );

    TDynArr<int>* r = TDynArr_Create<int>(10);

    for( int i = 0; i < r->capacity(); ++i )
    {
        *r += i;
    }

    for( int i = 0; i < r->size(); ++i )
    {
        Memo1->Lines->Add( IntToStr( r->at(i) ));
    }
    TDynArr_Free(r);
    Memo1->Lines->Add( (r==0) ? "null" : IntToStr((int)r).c_str()   );

    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        //
}
//---------------------------------------------------------------------------
