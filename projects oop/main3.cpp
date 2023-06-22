#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

class Book
{
    private:
        string name;
        string author;
        double price;
        
    public:
 Book():name("unkown"),author("unkown"),price(0)
{

}
 Book(string name,string author,double price):name(name),author(author),price(price)
{

}
void set_name(string n)
{
    name =n;
}
void set_author(string auth)
{
    author =auth;
}
void  set_price(double pr)
{
    price = pr;
}

string  get_name()
{
    return name;
}
string  get_author()
{
    return author;
}
double  get_price()
{
    return price;
}
 ~Book()
{

}
};



int main(int argc, char const *argv[])
{ 
    int ch;
    queue<Book>book_list;
    do
    {
        cout<<"-----Main Menu-----"<<endl;
        cout<<"1- Display all book"<<endl;
        cout<<"2- Add Book"<<endl;
        cout<<"3- Up data Book"<<endl;
        cout<<"4- Delete book"<<endl;
        cout<<"5- search book"<<endl;
        cout<<"6- Exit"<<endl;
        cout<<"Enter your choice: ";cin >>ch;
        while(cin.fail()) 
        {
            cout <<"Error enter the integer number: ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >>ch;
        }
        if  (ch==1)
        {
            queue<Book>book_list_swap;
            Book b_swap;
            if (book_list.empty())
                cout<<"There no book to display..."<<endl;
            else
            {
                cout<<"Book Name\t\tBook Author\t\tprice"<<endl;
                while (!book_list.empty())
                    {
                        Book b(book_list.front());
                        cout <<b.get_name()<<"\t\t\t"<<b.get_author()<<"\t\t\t"<<b.get_price()<<endl;
                        b_swap = book_list.front();
                        book_list.pop();
                        book_list_swap.push(b_swap);
                    }
                   book_list.swap(book_list_swap);
                
            }
        
        }
        else if  (ch==2)
        {
            int ch2;
            cout<<"Are you want Add Book ?"<<endl<<"if you want to Add Book enter 1\t\tif you want Bake enter 0"<<endl<<"Enter your choice: ";cin >>ch2;
            if (ch2==1)
            {
                Book b;
                string n,auth;
                double pr;
                cout<<"Enter Book name: ";cin>>n;
                cout<<"Enter Book author: ";cin>>auth;
                cout<<"Enter Book price: ";cin>>pr;
                while(cin.fail()) 
                {
                cout<<"you input string!!!!"<<endl;
                cout <<"Error enter the price (number): ";
                cin.clear();
                cin.ignore(256,'\n');
                cin >>pr;
                }
                b.set_name(n);
                b.set_author(auth);
                b.set_price(pr);
                book_list.push(b);
            }
            else
                {
                    while (ch2!=0 || ch2!=1)
                    {
                        cout<<"Invalid Choice"<<endl<<"Enter 0 or 1: ";cin >>ch2;
                        if (ch2==0)
                        {
                           break;
                        }
                        else if (ch2==1)
                        {
                            Book b;
                            string n,auth;
                            double pr;
                            cout<<"Enter Book name: ";cin>>n;
                            cout<<"Enter Book author: ";cin>>auth;
                            cout<<"Enter Book price: ";cin>>pr;
                            while(cin.fail()) 
                            {
                            cout<<"you input string!!!!"<<endl;
                            cout <<"Error enter the price (number): ";
                            cin.clear();
                            cin.ignore(256,'\n');
                            cin >>pr;
                            }
                            b.set_name(n);
                            b.set_author(auth);
                            b.set_price(pr);
                            book_list.push(b);
                            break;
                        }
                        
                        
                    }
                    
                }
            
            
        }
        else if  (ch==3)
        {
            int ch2;
            cout<<"Are you want Up data Book ?"<<endl<<"if you want to Up data Book enter 1\t\tif you want Bake enter 0"<<endl<<"Enter your choice: ";cin >>ch2;
            if (ch2==1)
            {
               queue<Book>book_list_swap;
                Book b_swap;
                Book old_book;
                string old_name,old_author;
                double old_price;
                if (book_list.empty())
                    cout<<"The book list is empty!"<<endl;
                else
                {
                    cout<<"Enter the old Book name: ";cin>>old_name;
                    cout<<"Enter the old Book author: ";cin>>old_author;
                    cout<<"Enter the old Book price: ";cin>>old_price;
                    while (!book_list.empty())
                        {
                            old_book = book_list.front();
                            if (old_name==old_book.get_name() && old_author== old_book.get_author() && old_price ==old_book.get_price())
                            {
                                string new_name,new_author;
                                double new_price;
                                Book new_book;
                                cout<<"Enter the new Book name: ";cin>>new_name;
                                while (new_name == old_name)
                                {
                                        cout<<"it is not new name"<<endl;
                                        cout<<"Enter the new Book name: ";cin>>new_name;
                                }
                                cout<<"Enter the new Book author: ";cin>>new_author;
                                 while (new_author == old_author)
                                    {
                                        cout<<"it is not new name"<<endl;
                                       cout<<"Enter the new Book author: ";cin>>new_author;
                                    }
                                
                                cout<<"Enter the new Book price: ";cin>>new_price;
                                 while (new_price == old_price)
                                    {
                                        cout<<"it is not new name"<<endl;
                                        cout<<"Enter the new Book price: ";cin>>new_price;
                                    }
                                
                                new_book.set_name(new_name);
                                new_book.set_author(new_author);
                                new_book.set_price(new_price);
                                old_book = new_book;
                                book_list.pop();
                                book_list.push(old_book);
                            }
                                b_swap = book_list.front();
                                book_list.pop();
                                book_list_swap.push(b_swap);
               
                        }
                        while (!book_list.empty())
                        {
                            b_swap = book_list.front();
                            book_list.pop();
                            book_list_swap.push(b_swap);
                        }
                        book_list.swap(book_list_swap);
                    //break;
                }
            }
            else
                {
                    while (ch2!=0 || ch2!=1)
                    {
                        cout<<"Invalid Choice"<<endl<<"Enter 0 or 1: ";cin >>ch2;
                        if (ch2==0)
                        {
                           break;
                        }
                        else if (ch2==1)
                        {
                            queue<Book>book_list_swap;
                            Book b_swap;
                            Book old_book;
                            string old_name,old_author;
                            double old_price;
                            if (book_list.empty())
                                cout<<"Not found a book,the book list is empty"<<endl;
                    else
                    {
                        cout<<"Enter the old Book name: ";cin>>old_name;
                        cout<<"Enter the old Book author: ";cin>>old_author;
                        cout<<"Enter the old Book price: ";cin>>old_price;
                        while (!book_list.empty())
                            {
                                old_book = book_list.front();
                                if (old_name==old_book.get_name() && old_author== old_book.get_author() && old_price ==old_book.get_price())
                                {
                                    string new_name,new_author;
                                    double new_price;
                                    Book new_book;
                                    cout<<"Enter the new Book name: ";cin>>new_name;
                                    while (new_name == old_name)
                                    {
                                            cout<<"it is not new name"<<endl;
                                            cout<<"Enter the new Book name: ";cin>>new_name;
                                    }
                                    cout<<"Enter the new Book author: ";cin>>new_author;
                                    while (new_author == old_author)
                                        {
                                            cout<<"it is not new name"<<endl;
                                        cout<<"Enter the new Book author: ";cin>>new_author;
                                        }
                                    
                                    cout<<"Enter the new Book price: ";cin>>new_price;
                                    while (new_price == old_price)
                                        {
                                            cout<<"it is not new name"<<endl;
                                            cout<<"Enter the new Book price: ";cin>>new_price;
                                        }
                                    
                                    new_book.set_name(new_name);
                                    new_book.set_author(new_author);
                                    new_book.set_price(new_price);
                                    old_book = new_book;
                                    book_list.pop();
                                    book_list.push(old_book);
                                }
                                b_swap = book_list.front();
                                book_list.pop();
                                book_list_swap.push(b_swap);
                            }
                            while (!book_list.empty())
                            {
                                b_swap = book_list.front();
                                book_list.pop();
                                book_list_swap.push(b_swap);
                            }
                            book_list.swap(book_list_swap);
                            
                    }
                    break;
                        }
                        
                        
                    }
                    
                }
                
        }
        else if  (ch==4)
        {
            int ch2;
            cout<<"Are you want Delete Book ?"<<endl<<"if you want to Delete Book enter 1\t\tif you want Bake enter 0"<<endl<<"Enter your choice: ";cin >>ch2;
            if (ch2==1)
            {
                queue<Book>book_list_swap;
                Book b_swap;
                Book b;
                string Delete_name,Delete_author;
                double Delete_price;
                if (book_list.empty())
                    cout<<"The book list is empty!"<<endl;
                else
                {
                    cout<<"Enter the name of Book want Delete: ";cin>>Delete_name;
                    // cout<<"Enter the old Book author: ";cin>>Delete_author;
                    // cout<<"Enter the old Book price: ";cin>>Delete_price;
                    while (!book_list.empty())
                        {
                            b = book_list.front();
                            if (Delete_name==b.get_name() )//&& Delete_author== b.get_author() && Delete_price ==b.get_price())
                            {
                                book_list.pop();
                                cout<<"the book is Delete!"<<endl;
                                break;
                                break;
                            }
                            b_swap = book_list.front();
                            book_list.pop();
                            book_list_swap.push(b_swap);
                        }
                        book_list.swap(book_list_swap);
                }
            }
            else
                {
                    while (ch2!=0 || ch2!=1)
                    {
                        cout<<"Invalid Choice"<<endl<<"Enter 0 or 1: ";cin >>ch2;
                        if (ch2==0)
                        {
                           break;
                        }
                        else if (ch2==1)
                        {
                            queue<Book>book_list_swap;
                            Book b_swap;
                            Book b;
                            string Delete_name,Delete_author;
                            double Delete_price;
                            if (book_list.empty())
                                cout<<"The book list is empty!"<<endl;
                            else
                            {
                            cout<<"Enter the name of Book want Delete: ";cin>>Delete_name;
                            // cout<<"Enter the old Book author: ";cin>>Delete_author;
                            // cout<<"Enter the old Book price: ";cin>>Delete_price;
                            while (!book_list.empty())
                                {
                                    b = book_list.front();
                                    if (Delete_name==b.get_name() )//&& Delete_author== b.get_author() && Delete_price ==b.get_price())
                                    {
                                        book_list.pop();
                                        cout<<"the book is Delete!"<<endl;
                                        break;
                                        break;
                                    }
                                    b_swap = book_list.front();
                                    book_list.pop();
                                    book_list_swap.push(b_swap);
                                }
                                book_list.swap(book_list_swap);
                                
                            }
                            break;
                        }
                        
                        
                    }
                    
                }
            
            
        }
        else if  (ch==5)
        {
            int ch2;
            cout<<"Are you want search Book ?"<<endl<<"if you want to search Book enter 1\t\tif you want Bake enter 0"<<endl<<"Enter your choice: ";cin >>ch2;
            if (ch2==1)
            {
                queue<Book>book_list_swap;
                Book b_swap;
                Book b;
                int id =0;
                string search_name,search_author;
                double search_price;
                if (book_list.empty())
                    cout<<"Not found a book,the book list is empty!"<<endl;
                else
                {
                    int counter = 0;
                    cout<<"Enter the search Book name: ";cin>>search_name;
                    // cout<<"Enter the search Book author: ";cin>>search_author;
                    // cout<<"Enter the search Book price: ";cin>>search_price;
                    while (!book_list.empty())
                        {
                            
                            b = book_list.front();
                            id++;
                            if (search_name==b.get_name())
                            {
                                counter++;
                                cout<<"Id: "<<id<<endl;
                                cout<<"Book Name\t\tBook Author\t\tprice"<<endl;
                                cout <<b.get_name()<<"\t\t\t"<<b.get_author()<<"\t\t\t"<<b.get_price()<<endl;
                            }
                            b_swap = book_list.front();
                            book_list.pop();
                            book_list_swap.push(b_swap);
                        }
                            book_list.swap(book_list_swap);
                        cout<<"books have the same name in book shop is: "<<counter<<endl;
                }
            }
            else
                {
                    while (ch2!=0 || ch2!=1)
                    {
                        cout<<"Invalid Choice"<<endl<<"Enter 0 or 1: ";cin >>ch2;
                        if (ch2==0)
                        {
                           break;
                        }
                        else if (ch2==1)
                        {
                            queue<Book>book_list_swap;
                            Book b_swap;
                            Book b;
                            int id =0;
                            string search_name,search_author;
                            double search_price;
                            if (book_list.empty())
                                cout<<"Not found a book,the book list is empty!"<<endl;
                            else
                            {
                                int counter = 0;
                                cout<<"Enter the search Book name: ";cin>>search_name;
                                // cout<<"Enter the search Book author: ";cin>>search_author;
                                // cout<<"Enter the search Book price: ";cin>>search_price;
                                while (!book_list.empty())
                                    {
                                        
                                        b = book_list.front();
                                        id++;
                                        if (search_name==b.get_name())
                                        {
                                            counter++;
                                            cout<<"Id: "<<id<<endl;
                                            cout<<"Book Name\t\tBook Author\t\tprice"<<endl;
                                            cout <<b.get_name()<<"\t\t\t"<<b.get_author()<<"\t\t\t"<<b.get_price()<<endl;
                                        }
                                        b_swap = book_list.front();
                                        book_list.pop();
                                        book_list_swap.push(b_swap);
                                    }
                                        book_list.swap(book_list_swap);
                                cout<<"books have the same name in book shop is"<<counter<<endl;
                            }
                            break;
                        }
                        
                        
                    }
                    
                }
            
        }
        else if (ch==6)
        {
            cout<<"The program Exit"<<endl;
        } 
        else
        {
            cout<<"Invalid Choice,enter number for 1 to 6"<<endl;
        }
    } while (ch != 6);
    
    
    return 0;
}