#include <iostream>
#include <vector>

using namespace std;
/**
 * @brief prints the elements in the vector and their memory locations
 * 
 * @param v - vector of integers
 */

 void PrintMemVec(vector<int> v)
 {
    printf("Vector - Each int is worth %lu bytes\n", sizeof(v[0]));
    for(int i = 0; i < v.size(); i++)
    {
        printf("Value :%i at Memory Location: %p\n", v[i], &v[i]);
    }
 }

 void incVecBy10(vector<int>  & v)
 {
    for(int i = 0; i < v.size(); i++)
    {
        v[i] += 10;
    }
 }

 int main()
 {
    //Create a constant integer called SIZE that is a value of 5
    const int SIZE =5;
    //Create a Vector of integers called vec that can hold up to 5 elements
    vector<int> vec = {1,2,3,4,5};
    //Use a for loop to populate vec with the values of 100 to 104
    for(int i = 0; i < 5; i++)
    {
        vec[i] = i + 100;
        cout<<vec[i]<<endl;
    }

    printf("Before Increment ------------\n");
    //Call PrintMemVec(...) on vec
    PrintMemVec(vec);

    //Call incVecBy10(...) on vec
    incVecBy10(vec);

    //Call PrintMemVec(...) on vec again to view the changes
    PrintMemVec(vec);

    //remove last element from vec (refer to docs https://cplusplus.com/reference/vector/vector/#google_vignette)
    vec.pop_back();
    
    printf("After Pop------------\n");
    //call printMemVec( ... ) on vec again to view the changes
    PrintMemVec(vec);

    // append 101 and 102 at the end of vec
    vec.push_back(101); 
    vec.push_back(102);
    
    // (refer to docs https://cplusplus.com/reference/vector/vector/#google_vignette)
    /*ask prof to explain this step a bit more*/

    printf("After Push------------\n");
    //call printMemVec( ... ) on vec again to view the changes
    PrintMemVec(vec);

    return 0;
 }
