#include <iostream>
#include <stdlib.h> // sran & rands() functions !

void swap(int* num1, int * num2); // function prototype declaration defined at
				 // the end of this file ! use for gloal scope
				// calls !
int ranInt() { 
    int ranNum {0};
    int lower {0}, upper {200}; 
    ranNum = (rand() % (upper + 1 - lower)) + lower;
    return ranNum;
}

class MultiArray {
    int rows, columns;
    int** arrLocation;

    void swap(int* num1, int* num2) {
        //std::cout << "Swapping " << *num1 << ", with " << *num2 << std::endl;
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
    }
public:
    
    int getRows() {return rows;}
    int getCols() {return columns;}
    int** arrayLocation() {return arrLocation;}
    void printSize() {
        for (int i {0}; i < rows; i++) {
            if (i == (rows -1)) {
                std::cout << "This Array has a size of [" << i << "]";
                for (int j {0}; j < columns; j++) {
                    if (j == (columns -1))
                        std::cout << "[" << j << "]\n";
                }
            }
        }
    }
    
    int randGen() {
        int ranNum {0};
        /*
        int i = 0;
        while (i++ < 10) { // this while loop will produce 10 random numbers !
            ranNum = (rand() % (12 + 1 - 8)) + 8;
            cout << ranNum << " ";
        }
        */
        
        int lower = 8, upper = 12;
        ranNum = (rand() % (upper + 1 - lower)) + lower;
        std::cout << "The random number is: " << ranNum << std::endl;
        return ranNum;
    }

    void ranFill() {
        std::cout << "Filling this array with random values !\n";
        for (int i {0}; i < rows; i++) {
	    for (int j {0}; j < columns; j++) {
		*(*(arrLocation + i) +j) = ranInt();
	    }
	}
    }


    void sort() {
/*
        for (int it {0}; it < (rows * columns); it++) {
            // this loop is for the total amount of comparisons to make
            for (int i {0}; i < rows; i++) {
                for (int j {0}; j < columns -1; j++) {
                    // this following loop will check through
		    // the entire dimension !
                    if (*(*arrLocation + i) +j >
			    *(*(arrLocation + i) +(j + 1)))
		    {
                        swap(*(arrLocation + i) + j,
					*(arrLocation + i)+ (j + 1));
                    }
                }
            }
            for (int i {0}; i < rows -1; i++) {
            // Our entire dimension is sorted, lets loop
	    // through a total times defined by the
            // first dimension. Lets check the end of the array with the
	    // beginning of the following dimension swap
	    // those values if necessary !
                if (*(*(arrLocation + i) + (columns - 1)) >
		    *(*(arrLocation + (i + 1))+ 0))
		{
                    swap(*(arrLocation + i) + (columns - 1),
			*(arrLocation + (i + 1) + 0));
                }
            }
        }
*/
        for (int i {0}; i < (rows * columns); ++i) {
            for (int j {0}; j < (rows * columns) - 1; ++j) {
                int cRow = j / columns; // the current row
                int cCol = j % columns; // the current column
                int nRow = (j + 1) / columns; // next row
                int nCol = (j + 1) % columns; // next column
                
                if (*(*(arrLocation + cRow) + cCol) >
		     *(*(arrLocation + nRow) + nCol))
	        {
                    swap(*(arrLocation + cRow) + cCol,
		      *(arrLocation + nRow) + nCol);
                }
            }
        }
    }

    int valueAt(int row, int column) {
        if (row >= rows) {
            // return -1 if array is out of bouds !
            std::cout << "Error array out of bounds ! ";
            return -1;
        }
        if (column >= columns) {
            // return -1 if array is out of bouds !
            std::cout << "Error array out of bounds ! ";
            return -1;
        }
        return *(*(arrLocation + row) + column);
    }
    
    int valueOutBound(int row, int column) {
        // naturally in c++ we'll end up getting a seg. fault
        // once we try to access memory we not aurthorized
        // to use we're still able to run this code with no error until
        // the boundarys of the array are voilated
        return *(*(arrLocation + row) + column);
    }
    
    void push(int num) {
    // push function w/ 1 int parameter will insert that value at [0][0]
        **arrLocation = num;
        std::cout << "Successfully pushed the value " << num
            << " to the array !\n";
    }
    
    bool binarySearch(int numToSearch) {
        static int arrDimen {0}; // there's a total of two dimensions
				// in a MultiArray object !
        static int beginning {0};
        static int end {columns};
        
        if (beginning > end || (beginning == 3 && end == 3)) {
            arrDimen = 0;
            beginning = 0;
            end = columns;
            std::cout << "the number: " << numToSearch << ", was not found !\n";
            return false;
        }
        int middle = (beginning + end) /2;
        if (*(*(arrLocation + arrDimen) + middle) == numToSearch) {
            beginning = 0;
            end = columns;
            arrDimen = 0;
            std::cout << "the number: " << numToSearch
		<< ", was found at the index ["
                << arrDimen << "][" << middle << "] !\n";
            return true;
        }
        else if (*(*(arrLocation + arrDimen) + middle) > numToSearch) {
            if (middle == 2 && arrDimen == 0) {
                end = columns;
                arrDimen += 1;
                return binarySearch(numToSearch);
            }
            end = middle -1;
            return binarySearch(numToSearch);
        }
        if (middle == 2 && arrDimen == 0) {
            beginning = 0;
            arrDimen += 1;
            return binarySearch(numToSearch);
        }
        beginning = middle + 1;
        return binarySearch(numToSearch);
    }
    
    void pop() {
        int **buffer = new int*[rows] {};
        for ( int i {}; i < rows; ++i) {
            buffer[i] = new int[columns -1] {};
        }
        for ( int i {}; i < rows; ++i) {
            for (int j {}; j < columns -1; ++j) {
                *(*(buffer + i) + j) = *(*(arrLocation + i) + j);
                continue;
            }
            continue;
        }
        // the bellow code will delete the current array at arrLocation
        for (int i {0}; i < rows; ++i)
            delete[] arrLocation[i];
        delete [] arrLocation;
        
        columns--; // lets subtract 1 from the current number of columns !
        
        // lets create a new array in the arrLocation variable,
	// then set those values to those copied over from the buffer variable !
        arrLocation = new int* [rows];
        for (int i {0}; i < rows; ++i) {
            arrLocation[i] = new int[columns];
        }
        // now let's fill that array with the buffer array !
        for (int i {0}; i < rows; ++i) {
            for (int j {0}; j < columns; ++j) {
                *(*(arrLocation + i) + j) = *(*(buffer +i) + j);
                continue;
            }
            continue;
        }
        
        // Finally lets clean up after ourselves and delete the buffer array !
        for (int i {0}; i < rows; ++i) {
            delete[] buffer[i];
        }
        delete[] buffer;
        std::cout << "Successfully destroyed the"
	    << " last element in this array !\n";
    }
    
    void printArray() {
        for (int i{0}; i < rows; i++) {
            for (int j{0}; j < columns; j++) {
                std::cout << "anArr[" << i << "][" << j << "] is: "
                    << *(*(arrLocation + i) + j) << std::endl;
                continue;
            }
        continue;
        }
	std::cout << std::endl;
    }

    void setArrAt(int row, int column, int val) {
        if (row >= rows)
            std::cerr << "Array is out of bounds !" << std::endl;
        if (column >= columns)
            std::cerr << "Array is out of bounds !" << std::endl;
        *(*(arrLocation + row) + column) = val;
    }
    
    MultiArray() {
        //ranArrSize();
        rows = randGen(); columns = randGen();
        
        arrLocation = new int*[rows] {};
        for (int i {}; i < rows; ++i) {
            arrLocation[i] = new int[columns] {};
        }
        
        std::cout << "This array has randomly been set to [" << rows - 1
	    << "][" << columns -1 << "]" << std::endl;
    }
    
    MultiArray(int rowz, int columnz) {
        rows = rowz;
        columns = columnz;
        arrLocation = new int*[rows] {};
        for (size_t i = 0; i < rows; ++i) {
            arrLocation[i] = new int[columns] {};
        }
        std::cout << "MultiArray constructor!\n";
        for (size_t i{0}; i < rows; ++i) {
            if (i == (rows -1))
                std::cout << "Array has size [" << i << "][";
        }
        for (size_t i {0}; i < columns; ++i) {
            if (i == (columns -1))
                std::cout << i << "]\n";
        }
    }
};

void pntSort(MultiArray * arr) {
    int rowz;
    int columnz;
    rowz = arr->getRows();
    columnz = arr->getCols();
    int** location = arr->arrayLocation();
    for (int i {0}; i < (rowz * columnz); ++i) {
        for (int j {0}; j < (rowz * columnz) - 1; ++j) {
            int curRow = j / columnz; // the current row
            int curCol = j % columnz; // the current column
            int nextRow = (j + 1) / columnz; // next row
            int nextCol = (j + 1) % columnz; // next column
            
            if (*(*(location + curRow) + curCol) >
		    *(*(location + nextRow) + nextCol))
	    {
                swap(*(location + curRow) + curCol,
			*(location + nextRow) + nextCol);
            }
        }
    }
}
void printMulti(MultiArray &arr);
int main() {
    srand((int) time(0));
    MultiArray anArr(5,8);
    anArr.push(5);
    std::cout << std::endl;
    std::cout <<  "anArr [0][0]: " << anArr.valueAt(0,0) << std::endl;
    anArr.push(50); // push will only change the value at the first element !
    std::cout << "anArr [0][0]: " << anArr.valueAt(0, 0) << std::endl;
    std::cout << std::endl;

    anArr.printArray();
    std::cout << anArr.valueAt(5, 8) << std::endl;
					    // we get -1 which is an error that
                                            //the array is our of bounds !
    anArr.setArrAt(0, 1, 15);
    std::cout << "anArr [0][1] is :" << anArr.valueAt(0,1) << std::endl;
    anArr.setArrAt(4, 7, 80);
    std::cout << "anArr [4][7] is: " << anArr.valueAt(4,7) << std::endl;
    anArr.pop(); // .pop() function deletes the last element in this array !
    std::cout << std::endl;
    std::cout << anArr.valueAt(4, 7) << std::endl; // we get -1 which is array
                                    // out of bounds error !
    /* how is this possible ? We defined an array of [4][7]
       yet we can't access the last element, THATS BECAUSE we just
       used the .pop() function which deletes the last element in the array !
    */
    std::cout << "anArr [4][6] is: " << anArr.valueAt(4, 6) << std::endl;
    anArr.pop();
    std::cout << std::endl;
    std::cout << anArr.valueAt(4, 6) << std::endl;
    anArr.printSize();
    
    /*
    the srand() function "seed rand" will feed (seed) the pseudo
    random number generator used
    by the rand() function ** THE SEED FOR THE rand() FUNCTION IS 1 BY DEFAULT 
    int ranNum = rand(); // no srand() funct has been called before rand(),
			 // so seed = 1
    cout << "Seed = 1, Random number: " << ranNum << endl;
    
    srand(time(0));
    int ranNum = rand();
    
    cout << "Seed = " << time(0) << endl;
    cout << "Random number is: " << ranNum << endl;
    */
    
    //MultiArray *multiArr = new MultiArray();
    
    MultiArray arr; // no need to use '()' which will try to look
		    // for a function rather than the class construtor.
		    // Leaving it as is will call the default constructor
    arr.printSize();
    arr.setArrAt(5,7, 15);
    arr.push(7);
    std::cout <<"arr [0][0] is: " << arr.valueAt(0,0) << std::endl;
    std::cout << "arr [5][7] is: " << arr.valueAt(5, 7) << std::endl;
    std::cout << "arr [" << arr.getRows() -1 << "]["
	<< arr.getCols() -1 << "] is: "
        << arr.valueOutBound(arr.getRows() -1, arr.getCols() -1) << std::endl;
	// still in bounds !
    
    /*
      the below code produces seg fault. cannot access array out of bounds ! use
      MultiArray.valueAt() method which provides an error checker
      for this problem.
      cout << "arr [" << arr.getRows() << "][" << arr.getCols() << "] is: "
         << arr.valueOutBound(arr.row(), arr.getCols()) << endl;
    */
    std::cout << arr.valueAt(arr.getRows(), arr.getCols()) << std::endl;
    arr.pop();
    arr.printSize();
    std::cout << std::endl;
    arr.printArray();
    
    MultiArray whicharr(2,3);
    whicharr.push(5);
    whicharr.setArrAt(0, 1, 10);
    whicharr.setArrAt(0, 2, 15);
    whicharr.setArrAt(1, 0, 20);
    whicharr.setArrAt(1, 1, 25);
    whicharr.setArrAt(1, 2, 30);
    whicharr.printArray();
    
    whicharr.binarySearch(5); // 1
    whicharr.binarySearch(15); // 1
    whicharr.binarySearch(3); // 0
    whicharr.binarySearch(0); // 0
    whicharr.binarySearch(30); // 1
    whicharr.binarySearch(-50); // 0
    whicharr.binarySearch(20); // 1
    whicharr.binarySearch(37); // 0
    whicharr.binarySearch(5); // 1
    whicharr.binarySearch(15); // 1
    whicharr.binarySearch(3); // 0
    whicharr.binarySearch(-5); // 0
    whicharr.binarySearch(10); // 1
    whicharr.binarySearch(55); // 0
    whicharr.binarySearch(70); // 0
    std::cout << std::endl;

    MultiArray unsorted(2,2);
    unsorted.push(15);
    unsorted.setArrAt(0, 1, 3);
    unsorted.setArrAt(1,0, 17);
    unsorted.setArrAt(1, 1, 7);
    std::cout << "Unsorted !\n";
    unsorted.printArray();
    unsorted.sort();
    std::cout << "Sorted !\n";
    unsorted.printArray();
    std::cout << "the value of ran is: " << ranInt() << std::endl;
    std::cout << std::endl;

    MultiArray unsortRan(3,3);
    /*
    unsortRan.push(ranInt());
    unsortRan.setArrAt(0,1, ranInt());
    unsortRan.setArrAt(0,2, ranInt());
    unsortRan.setArrAt(1,0, ranInt());
    unsortRan.setArrAt(1,1, ranInt());
    unsortRan.setArrAt(1,2, ranInt());
    unsortRan.setArrAt(2,0, ranInt());
    unsortRan.setArrAt(2,1, ranInt());
    unsortRan.setArrAt(2,2, ranInt());
    */
    unsortRan.ranFill();
    std::cout << "Unsorted !\n";
    unsortRan.printArray();
    unsortRan.sort();

    std::cout << "Sorted !\n";
    unsortRan.printArray();

    MultiArray ranArr;
    ranArr.ranFill();
    std::cout << "Unsorted !\n";
    ranArr.printArray();
    ranArr.sort();
    std::cout << std::endl;
    std::cout << "Sorted !\n";
    ranArr.printArray();

    // make use of pointers !
    std::cout << "Using pointer for the following array !\n";
    MultiArray * pntMultiArr = new MultiArray;
    pntMultiArr->ranFill();
    std::cout << "Unsorted !\n";
    pntMultiArr->printArray();
    pntSort(pntMultiArr);
    std::cout << "Sorted !\n";
    pntMultiArr->printArray();
    printMulti(ranArr);
    return 0;
}
void printMulti(MultiArray &arr) {
    for (int i {0}; i < arr.getRows(); i++) {
	for (int j{0}; j < arr.getCols(); j++) {
	    std::cout << *(*(arr.arrayLocation() + i) + j) << std::endl;
	}
    }
}
void swap(int* num1, int *num2) { // num1 has a greater value than num2
    int buffer = *num1;
    *num1 = *num2;
    *num2 = buffer;
}
