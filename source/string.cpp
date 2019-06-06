#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "string.hpp"


/** Constructors */
String::String(){
    array = new char[1];
    array[0] = '\0';
    length = 0;
};

String::String(char* c){
    int i = 0;
    while(c[i]) ++i;

    array = new char[i+1];

    length = i;

    for(int j = 0; j < i; ++j) array[j] = c[j]; 

    array[i] = '\0';
};

String::String(char c){
    array = new char[2];
    array[0] = c;
    array[1] = '\0';
    length = 1;
};

/** Destructors */
String::~String(){
    delete[] array;
};

/** at(int position)
 * Returns the character at the given position, throws an exception if the
 * position is out of bounds.
 * O(1) Omega(1) theta(1)
 */
char String::at(int b) const{
    if(b < 0 || b >= this->length){
        throw std::out_of_range("out of range");
    }
    else return(this->array[b]);
};

/** empty()
 * Returns whether or not the string is empty.
 * O(1) Omega(1) theta(1)
 */
bool String::empty() const{
    if(array[0] == '\0'){
        return true;
    }
    else{
        return false;
    }
};

/** size()
 * Returns the number of characters in the string.
 * O(n) Omega(1)
 */
unsigned int String::size() const{
    int i = 0;
    while(this->array[i] != '\0') ++i;

    return i;
};

/** capacity()
 * Returns the number of characters that the string can hold.
 * O(1)
 */
unsigned int String::capacity() const{
    return(this->length);
};

/** reserve(int extra)
 * Reserves extra amount of characters, extending the capacity of the string.
 * O(2n) Omega(2n) theta(2n)
 */
void String::reserve(unsigned int extra){
    int newLen = this->length + extra;

    char* temp = new char[length+1];
    for(int i = 0; i < length; ++i) temp[i] = this->array[i];
    delete[] array;

    this->array = new char[newLen + 2];
    for(int i = 0; i < length; ++i) this->array[i] = temp[i];

    length = newLen;

    this->array[length] = '\0';
};

/** insert(char c, int index)
 * Inserts the given character `c` into the string at the given index.
 * If the index is out of bounds the character should appended / prepended.
 * O(n) Omega(n) theta(n)
 */
void String::insert(char c, int a){
    String current = new char[this->length];
    for(int i = 0; i < this->length; ++i) current.array[i] = this->array[i];
    if(a < current.capacity()) this->array[a] = c;
    else current.append(c);
};

/** erase(char)
 * Erases all copies of the given character from the string.
 * O(?)
 */
void String::erase(char c){
    String current;
    current.array = new char[this->length];
    for(int i = 0; i < current.capacity(); i++){
        if(this->array[i] != c) current.append(c);
        else current.length--;
    }
    delete[] this->array;
    this->array = new char[current.length + 1];
    for(int i = 0; i < current.length; ++i) this->array[i] = current.array[i];
    this->array[current.length] = '\0';
};

/** remove(int index)
 * Removes the character at the given index.
 * O(?)
 */
void String::remove(int a){
    String current = this->array;
    current = new char[current.size() - 1];
    for(int i = 0; i < current.capacity(); i++){
        if(i != a) current.append(this->array[i]);
    }
    delete[] this->array;
    this->array = current.array;
};

/** append(char)
 * Appends the given character to the string.
 * O(?)
 */
void String::append(char c){
    String current;
    current.array = new char[this->length+2];
    for(int i = 0; i < this->length; ++i) current.array[i] = this->array[i];
    current.array[this->length] = c;

    delete[] this->array;
    this->array = new char[length + 2];
    for(int i = 0; i <= this->length; ++i) this->array[i] = current.array[i];
    this->length++;
    this->array[this->length] = '\0';

};

/** prepend(char)
 * Prepends the given character to the string.
 * O(?)
 */
// void String::prepend(char c){
//     String current = this->array;
//     current = new char[current.size() + 1];
//     current.array[0] = c;
//     for(int i = 1; i < current.capacity(); ++i) current.append(c);
//     delete[] this->array;
//     this->array = current.array;
// };

/** compare(char* or String)
 * Returns whether or not the string is equal with the one given.
 * O(n) Omega(1)
 */
bool String::compare(char* c) const{
    String comp(c);
    String current(this->array);
    for(int i = 0; i < this->length; ++i){
        if(comp.array[i] == '\0' || comp.array[i] != current.array[i]) return false;
    }
    return true;
};

bool String::compare(String& comp) const{
    String current(this->array);
    return current.compare(comp.array);
};

/** concate(char* or String)
 * Concatenates the string with the given character array, or string.
 * O(2n) Omega(2n) theta(2n)
 */
void String::concatenate(char* c){
    String current(this->array);
    String con(c);
    current.reserve(con.length);
    for(int i = 0; i < con.length; i++) current.append(con.array[i]);
    delete[] this->array;
    this->array = new char[current.length+1];
    for(int i = 0; i < current.length; i++) this->array[i] = current.array[i];
    this->array[this->length] = '\0';
};

void String::concatenate(String& c){
    String current(this->array);
    String con(c.array);
    current.reserve(con.length);
    for(int i = 0; i < con.length; i++) current.append(con.array[i]);
    delete[] this->array;
    this->array = current.array;
    this->array = new char[current.length+1];
    for(int i = 0; i < current.length; i++) this->array[i] = current.array[i];
    this->array[this->length] = '\0';
};

/** find(char* or char or String)
 * Returns the index of the first occurrence of the character array, char, or
 * string given. Should return length if not found.
 * O(?)
*/
// unsigned int String::find(char* c, int start = 0) const{
//     String current = this->array;
//     String find = c;
//     start = current.find(c[0]);
//     if(start == current.size()){
//         return current.size();
//     }
//     else{
//         for(int i = 0; i < find.size(); i++){
//             if(current.array[start] != find.array[i]){
//                 current.erase(find.array[0]);
//                 current.find(c, 0);
//             } 
//         }
//         return start;
//     }
// };

// unsigned int String::find(char c, int start = 0) const{
//     String current = this->array;
//     if(c == this->array[start] || start == current.size()) return start;
//     else current.find(c, ++start);
// };

// unsigned int String::find(String&, int start = 0) const{

// };

// // /** reverse()
// //  * Reverses the string in-place.
// //  * O(?)
// //  */
// void String::reverse(){

// };

// /** shift(int)
//  * Shifts all characters ASCII values in the array upwards or downwards by the
//  * amount given. This method should also prevent characters from becoming
//  * null, or exceeding the ASCII range.
//  * O(?)
//  */
// void String::shift(int){

// };

// /** toInt()
//  * Returns the string as an integer, if it can be represented as one.
//  * Otherwise throws an exception
//  * O(?)
//  */
int String::toInt() const{

    return 0;
};

/** substr(start, end)
 * Returns the string contained between [start, end).
 * O(?)
 */
String String::substr(int, int) const{
    String current = new char[1];
    return current;
};