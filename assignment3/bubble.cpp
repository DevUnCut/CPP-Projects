#include <iostream>
using namespace std;

bool binSearch (int arr[], int numToSearch, int beginning, int end) {
    if (beginning > end)
	return false;
    int middle = (beginning + end)/2;
    if (arr[middle] == numToSearch) // return true if we find the numToSearch
	return true;
    else if (arr[middle] > numToSearch) // search to the left of the array 
	return binSearch(arr, numToSearch, beginning, middle-1); // recursion
    else // search to the right of the array
	return binSearch(arr, numToSearch, middle+1, end); // recursion
}

int bigger(int arr[], int i1, int i2) {
    if (arr[i1] == arr[i2])
	return 0; // return 0 if both values are the same !
    else if (arr[i1] < arr[i2])
	return 1; // if our 1st idx is bigger than the 2nd idx
    else
	return -1; // return -1 if it is not bigger
}

void swap (int arr[], int i1, int i2) {
    int tmp;
    tmp = arr[i1];
    arr[i1] = arr[i2];
    arr[i2] = tmp;
}

template <int len>
void printList (int (&arr)[len]) {
    string out = "[";
    bool first = true;
    for (auto i:arr) {
	if (first)
	    first = false;
	else
	    out += ",";
	out += to_string(i);
    }
    out += "]";
    cout << out << "\n";
}

int main() {
    int arr[] = {5, 6, 3, 4, 0, 2, 1};
    int anotherArr[] = {6, 5, 4, 3, 2, 1, 0};
    int anArr[] = {43, 27, 1, 11, 99, 44, 2, 6};
//    printList (arr);
    // we need to find the length of each array to properly check their values
    int len1 = sizeof(arr) / sizeof(arr[0]); // len of arr
    int len2 = sizeof(anotherArr) / sizeof(anotherArr[0]); // len of anotherArr
    int len3 = sizeof(anArr) / sizeof(anArr[0]); // len of anArr

    int last1 = len1 -1;
    int last2 = len2 -1;
    int last3 = len3 -1;
    bool done1 = last1 <= 0;
    bool done2 = last2 <= 0;
    bool done3 = last3 <= 0;

    while (done1 == false) {
	done1 = true;
	for (int i = 0; i < len1-1; i++) {
	    if (bigger(arr, i, i+1) == -1) {
	        swap(arr, i, i+1);
	        done1 = false;
	    }
	    last1 -= 1;
	}
    }
    printList (arr);

//    printList (anotherArr);
    while (done2 == false) {
	done2 = true;
	for (int i = 0; i < len2-1; i++) {
	    if (bigger(anotherArr, i, i+1) == -1) {
		swap (anotherArr, i, i+1);
		done2 = false;
	    }
	    last2 -= 1;
	}
    }
    printList (anotherArr);

//    printList (anArr);
    while (done3 == false) {
	done3 = true;
	for (int i = 0; i < len3-1; i++) {
	    if (bigger(anArr, i, i+1) == -1) {
	        swap (anArr, i, i+1);
                done3 = false;
	    }
            last3 -= 1;
        }
    }
    printList (anArr);


    if (binSearch(arr, 5, 0, len1-1))
	cout << "5 is in the array\n";
    else
	cout << "5 is not in the array\n";

    if (binSearch(arr, 6, 0, len1-1))
	cout << "6 is in the array\n";
    else
	cout << "6 is not in the array\n";

    if (binSearch(arr, 15, 0, len1-1))
	cout << "15 is in the array\n";
    else
	cout << "15 is not in the array\n";


    if (binSearch(anotherArr, 5, 0, len2-1))
        cout << "5 is in the array\n";
    else
        cout << "5 is not in the array\n";

    if (binSearch(anotherArr, 6, 0, len2-1))
        cout << "6 is in the array\n";
    else
        cout << "6 is not in the array\n";

    if (binSearch(anotherArr, 15, 0, len2-1))
        cout << "15 is in the array\n";
    else
        cout << "15 is not in the array\n";


    if (binSearch(anArr, 5, 0, len3-1))
        cout << "5 is in the array\n";
    else
        cout << "5 is not in the array\n";

    if (binSearch(anArr, 6, 0, len3-1))
        cout << "6 is in the array\n";
    else
        cout << "6 is not in the array\n";

    if (binSearch(anArr, 15, 0, len3-1))
        cout << "15 is in the array\n";
    else
        cout << "15 is not in the array\n";
    if (binSearch(anArr, 44, 0, len3-1))
	cout << "44 is in the array\n";
    else
	cout << "44 is not in the array\n";
    return 0;
}
