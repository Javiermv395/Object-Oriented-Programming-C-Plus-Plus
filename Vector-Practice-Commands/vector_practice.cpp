#include <iostream>
#include <vector>
using namespace std;

int main()
{
    /*Vectors can be initialized without a size */
    vector<int> vec = {1,2,3,4,5};     // A vector is initialized by (vector<data type> name = {elements})
    cout<< vec[2] <<endl;              // Accessing elements in a vector is similar to accessing elements in an array
    cout<< vec.front() <<endl;         // this displays the first element of the vector
    cout<< vec.back() <<endl;          // this displays the last element of the vector
    cout<< vec.size() <<endl;          // this displays the number of elements in the vector
    cout<< vec.capacity() <<endl;      // this displays the number of elements the vector can hold before it needs to resize
    vec.push_back(9);                  // this adds an element to the end of the vector with the number between the parenthses as the value
    vec.pop_back();                    // this removes the last element of the vector but it does not decrease the capacity of the vector
    vec.shrink_to_fit();               // this decreases the capacity of the vector to the number of elements in the vector


    vec.insert(vec.begin(), 5);        // this inserts an element at the beginning of the vector with five being the element inserted
    vec.insert(vec.begin() + 2, 7);    // this inserts an element at the third position of the vector with seven being the element inserted

    vec.erase(vec.begin());        // this removes the element at the first position of the vector

    for (int i = 0; i < vec.size(); i++) // this loop prints out the elements in the vector
    {
        cout<< vec[i] <<endl;
    }
    return 0;
}