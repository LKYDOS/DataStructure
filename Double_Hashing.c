/*
I, <Your Full Name>, am submitting the assignment for
an individual project.
I declare that the assignment here submitted is original except for
source material explicitly acknowledged, the piece of work, or a part
of the piece of work has not been submitted for more than one purpose
(i.e. to satisfy the requirements in two different courses) without
declaration. I also acknowledge that I am aware of University policy
and regulations on honesty in academic work, and of the disciplinary
guidelines and procedures applicable to breaches of such policy and
regulations, as contained in the University website
http://www.cuhk.edu.hk/policy/academichonesty/.
It is also understood that assignments without a properly signed
declaration by the student concerned will not be graded by the
teacher(s).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const int hashTableSize = 29989;


struct Student {
    int studentid;
    char name[50];
    int age;
    char dept[50];
    char gender;
};


/**
* @brief: get the hash value of a key
* @param: 1. key 
* @return: hash value
* @usage: int hashValue = HashFunction1(yourKey)
*/
int HashFunction1(int key) {
    return key % hashTableSize;
}

/**
* @brief: get the hash value of a key
* @param: 1. key 
* @return: hash value
* @usage: int hashValue = HashFunction2(yourKey)
*/
int HashFunction2(int key) {
    return 1 + key % 1069;
}

/**
* @brief: insert a StudentNode into a hashTable. If the student has existed, modify its other attributes with new one
* @param: 1. hashTable   2. StudentNode
* @return: void
* @usage: InsertHashTable(yourHashTable, yourKey, yourRecord)
*/

void InsertHashTable(struct Student* hashTable[], struct Student* StudentNode) 
{
    // WRITE YOUR CODE HERE
    for (int k= 0 ; k < 29989-1 ; k++){
        if (hashTable[HashFunction1(HashFunction1(StudentNode->studentid) + k*HashFunction2(StudentNode->studentid))] == NULL){
            hashTable[HashFunction1(HashFunction1(StudentNode->studentid) + k*HashFunction2(StudentNode->studentid))] = StudentNode;
            break;
        }
    }
            

}



int SearchHashTable(struct Student* hashTable[], int key) {
    // WRITE YOUR CODE HERE
    for (int j = 0 ; j < 29989-1 ; j++){
        if (hashTable[HashFunction1(HashFunction1(key) + j*HashFunction2(key))] == NULL)
            return -1;
        else if (hashTable[HashFunction1(HashFunction1(key) + j*HashFunction2(key))]->studentid == key)
            return key;
    }
return -1;
}



int main() {
    struct Student* hashTable[hashTableSize];
    for (int i = 0; i < hashTableSize; i++) {
        hashTable[i] = NULL;
    }
    
    int insertNum, searchNum;
    int key;
    scanf("%d", &insertNum);
    for (int i = 0; i < insertNum; i++) {
        struct Student* s = (struct Student*)malloc( sizeof(struct Student) );
        scanf("%d,%[^,],%d,%[^,],%c", &s->studentid, s->name, &s->age, s->dept, &s->gender);		
        InsertHashTable(hashTable, s);
    }
    
    scanf("%d", &searchNum);
    for (int i = 0; i < searchNum; i++) {
        scanf("%d", &key);
        int index = SearchHashTable(hashTable, key);
        printf("%d\n", index);
    }
    printf("\n");
}

// -------------------------------------------End of Code-------------------------------------------

// Input:
// First line: number of students(named insertNum)
// In the next insertNum lines,
// each line contains a student with the following information separated by commas:
// studentid, name, age, dept, gender

// Next line: num of search operation (named searchNum)
// In the next searchNum lines, 
// each line contains one integer which is search key

// Output:
// searchNum lines of search result. 
// If the key exists, output the index in the hash table.
// If the key does not exist, output "-1".

// Sample Input 1:
// 3
// 5678,Jane Smith,21,Mathematics,f
// 9999,Robert Lee,19,Physics,m
// 2468,Samantha White,22,Biology,f
// 5
// 5678
// 1111
// 9999
// 2468
// 3333


// Sample Output 1:
// 5678
// -1
// 9999
// 2468
// -1