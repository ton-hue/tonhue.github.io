//============================================================================
// Name        : Sorting Example Final
// Author      : Tonio Thurman
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Vector Sorting Algorithms
//============================================================================

#include <algorithm> //**Source Code -inclusions to display time, read csv parser, and algorithms
#include <iostream>
#include <time.h>

#include "CSVparser.hpp"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// **Source Code - forward declarations

double strToDouble(string str, char ch);

// **Source Code - this sections holds all bid information, each string is meta data for the bid. 
struct Bid {
    string bidId; // unique identifier
    string title;
    string fund;
    double amount;
    Bid() {
        amount = 0.0;
    }
};

//============================================================================
// Static methods used for testing
//============================================================================

/** **Source Code - This displays title and amount of bid
 * using character output. 
 * 
 * Display the bid information to the console (std::out)
 *
 * @param bid struct containing the bid info
 */
void displayBid(Bid bid) {
    cout << bid.bidId << ": " << bid.title << " | " << bid.amount << " | " //shows how the bid will be displayed in the program 
            << bid.fund << endl;
    return;
}

/**
 * Prompt user for bid information using console (std::in)
 *
 * @return Bid struct containing the bid info
 */
Bid getBid() {                                      //this gets the bid input information, after reviewing this I thought about using the
                                                    //id of the bid to delete the information but wanted to keep it simple for the user. 
                                                    //by using the exact amout allows less errors or mistake vs. the id of the bid. 
    Bid bid;

    cout << "Enter Id: ";  //**Source Code - this also uses character output to                        
    cin.ignore();         // display bid info, then returns bid. 
    getline(cin, bid.bidId);

    cout << "Enter title: ";
    getline(cin, bid.title);

    cout << "Enter fund: ";
    cin >> bid.fund;

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    bid.amount = strToDouble(strAmount, '$');

    return bid;
}

/**
 * **Source Code - Load a CSV file containing bids into a container
 *
 * @param csvPath the path to the CSV file to load
 * @return a container holding all the bids read
 */
vector<Bid> loadBids(string csvPath) {
    cout << "Loading CSV file " << csvPath << endl;

    // Define a vector data structure to hold a collection of bids.
    vector<Bid> bids;

    // **Source Code - initialize the CSV Parser using the given path reading the ebid monthly sales
    csv::Parser file = csv::Parser(csvPath);

    try {
        // **Source Code - loop to read rows of a CSV file - data structure to read the 40,000 bids from the csv file
        for (int i = 0; i < file.rowCount(); i++) {

            // Create a data structure and add to the collection of bids
            Bid bid;
            bid.bidId = file[i][1];
            bid.title = file[i][0];
            bid.fund = file[i][8];
            bid.amount = strToDouble(file[i][4], '$');

            //cout << "Item: " << bid.title << ", Fund: " << bid.fund << ", Amount: " << bid.amount << endl;

            // push this bid to the end
            bids.push_back(bid);
        }
    } catch (csv::Error &e) {
        std::cerr << e.what() << std::endl; //**Source Code - made to catch csv errors
    }
    return bids;
}

// FIXME (2a): Implement the quick sort logic over bid.title

/**
 * Partition the vector of bids into two parts, low and high
 *
 * @param bids Address of the vector<Bid> instance to be partitioned
 * @param begin Beginning index to partition
 * @param end Ending index to partition
 */
int partition(vector<Bid>& bids, int begin, int end) {  // **Source Code - sorts by title by comparing using boolean
	int low = begin; // **Source Code - integer made for low and high for boolean 
	int high = end;
	//mid point
	int piv = begin + (end - begin) / 2;
	bool done = false;
	while (!done) {
		while (bids.at(low).title.compare(bids.at(piv).title) < 0) {
			++low; //**Source Code - comparing bids to piv integer
		}
		while (bids.at(piv).title.compare(bids.at(high).title) < 0) {
			--high; //**Source Code - comparing piv bids to high integer
	}
		if (low >=high) {
			done = true; //**Source Code - if else statement to determine output
		} else {
			swap(bids.at(low), bids.at(high));

		++low;
		--high; //**Source Code - displays new low or high value
	}
	}
	return high;
}

/**
 * Perform a quick sort on bid title
 * Average performance: O(n log(n))
 * Worst case performance O(n^2))
 *
 * @param bids address of the vector<Bid> instance to be sorted
 * @param begin the beginning index to sort on
 * @param end the ending index to sort on
 */
void quickSort(vector<Bid>& bids, int begin, int end) {
	int mdp = 0;

	if (begin >= end) {
		return;
	}
	mdp = partition(bids, begin, end);
	quickSort(bids, begin, mdp);
	quickSort(bids, mdp + 1, end); //**Source Code - made to compare begin/end index for return

}
// FIXME (1a): Implement the selection sort logic over bid.title

/**
 * Perform a selection sort on bid title
 * Average performance: O(n^2))
 * Worst case performance O(n^2))
 *
 * @param bid address of the vector<Bid>
 *            instance to be sorted
 */
void selectionSort(vector<Bid>& bids) {
	int min;
	for (unsigned placr = 0; placr < bids.size(); ++placr) {   ////**Source Code - sort logic creation for bids 
		min = placr;
		for (unsigned hol = placr + 1; hol < bids.size(); ++hol) {
			if (bids.at(hol).title.compare(bids.at(min).title) < 0) {
				min = hol;
			}
		}
		if (min != placr) {
			swap(bids.at(placr), bids.at(min));
		}
	}
}

****//REMOVE BID ALGORITHM ADDED TO SOURCE CODE ************

//REMOVE BID ALGORITHM ADDED TO SOURCE CODE **ENHANCEMENT

/**
*Allows seller/user to input bid to delete if buyer is out bidded
*This alogrithm fit best with the bidding source code specifically for the loop
*pulling each bid fwd and decreasing the bids 
*
*/

int main()
		//In the csv file there were
        //40,000 bids from ebid monthly sells 
        //I used 6 elements to perform loop

{
	int buffBid[40000] = {3,6,9,1,2,4}; //using 6 elements 
	int bidDelete = 0; //for user to enter bids and stores bid
	int size = 6; //number of elements

	//shows seller the bids, so user can determine which bids to delete
    //The user can identify lowest bid to input into loop for deletion

	for (int i = 0; i < size; i++) 

	printf("%d", buffBid[i]);  //printing out each bid using buffBid integer
	printf("\n"); //space

	 //This prints so user can enter bid that is low or not needed anymore.
	printf("Enter Bid for Deletion: ")

	scanf("%d", &bidDelete); // stores in bidDelete int
	
	//algorithm loop, this begins the deletion process using i as the bid
	
	int i = 0;
			//while bid or [i] is less than size perform loop

		while (i < size) 	{
		if (buffBid[i] == delete)
	{
		if (i < (size - 1)) // decreases bid by 1 if i is less than 
		for (int j = i; j < (size - 1); j++)
		buffBid[j] = buffBid[j + 1]; //pull fwd each bid by 1
			size--; //decrease size
	}
		else i++;  //new value


		return 0;  //after decreasing size should return or continue with next bid deletion. 
	}

/*******************

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch //**Source Code - The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());    //removal of unwanted characters. 
    return atof(str.c_str());
}

/** //**Source Code - 2nd main funtion
 * The one and only main() method
 */
int main (int argc, char* argv[]) {

    // //**Source Code -  process command line arguments
    string csvPath;
    switch (argc) {
    case 2:
        csvPath = argv[1];
        break;
    default:
        csvPath = "eBid_Monthly_Sales.csv";
    }

    // Define a vector to hold all the bids
    vector<Bid> bids;

    // //**Source Code - Define a timer variable, displays ticks
    clock_t ticks;

    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Load Bids" << endl;
        cout << "  2. Display All Bids" << endl;
        cout << "  3. Selection Sort All Bids" << endl;
        cout << "  4. Quick Sort All Bids" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            // Initialize a timer variable before loading bids
            ticks = clock();

            // Complete the method call to load the bids
            bids = loadBids(csvPath);

            cout << bids.size() << " bids read" << endl;

            // Calculate elapsed time and display result
            ticks = clock() - ticks; // current clock ticks minus starting clock ticks
            cout << "time: " << ticks << " clock ticks" << endl;
            cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

            break;

        case 2:
            // Loop and display the bids read
            for (int i = 0; i < bids.size(); ++i) {
                displayBid(bids[i]);
            }
            cout << endl;

            break;

        // FIXME (1b): Invoke the selection sort and report timing results
        case 3:
                    // Initialize a timer variable before loading bids
                    ticks = clock();

                    // Complete the method call to load the bids
                    selectionSort(bids);

                    cout << bids.size() << " bids read" << endl;

                    // Calculate elapsed time and display result
                    ticks = clock() - ticks; // current clock ticks minus starting clock ticks
                    cout << "time: " << ticks << " clock ticks" << endl;
                    cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

                    break;
        // FIXME (2b): Invoke the quick sort and report timing results
        case 4:
                     // Initialize a timer variable before loading bids - //wanted to impliment this for the return of the bids for the removal algorithm
                     ticks = clock();                                       //Added buffBid to method for calling bids to display timing results. 

                     // Complete the method call to load the bids
                     quickSort(bids, buffBid, 0, bids.size() - 1);

                     cout << bids.size() << " bids read" << endl;

                     // Calculate elapsed time and display result
                     ticks = clock() - ticks; // current clock ticks minus starting clock ticks
                     cout << "time: " << ticks << " clock ticks" << endl;
                     cout << "time: " << ticks * 1.0 / CLOCKS_PER_SEC << " seconds" << endl;

                     break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
