#include <iostream>
#include <string.h>
struct Books{
    char title[50];
    char author[50];
    char subject[100];
    int  book_id;
    void printBook();
};
int main(void){
    Books Book1;
    /* Declare Book1 of type Books */
    Books Book2;
    /* Declare Book2 of type Books */
    /* book 1 specification */
    strcpy( Book1.title, "Heaven’s Devisl");
    strcpy( Book1.author, "William C. Dietz");
    strcpy( Book1.subject, "Starcraft novel");
    Book1.book_id = 6495407;
    /* book 2 specification */
    strcpy( Book2.title, "Misery");
    strcpy( Book2.author, "Stephen King");
    strcpy( Book2.subject, "Psychological thriller");
    Book2.book_id = 6495700;
    /* print Book1 info */
    Book1.printBook(); /* Print Book2 info */
    Book2.printBook();
return 0;
    
}
void Books::printBook(){
    std::cout << "Book title : " << title << "\n";
    std::cout << "Book author : " << author << "\n";
    std::cout << "Book subject : " << subject << "\n";
    std::cout << "Book book_id : " << book_id << "\n";
    std::cout << std::endl;
    
}
