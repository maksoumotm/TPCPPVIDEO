#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Frame {
public:
    // Method to define the width of the video
    int defineWidth() {
        cout << "Enter the width of the video = ";
        cin >> m_Width;
        return m_Width;
    }

    // Method to define the height of the video
    int defineHeight() {
        cout << "Enter the height of the video = ";
        cin >> m_Height;
        return m_Height;
    }

    // Method to generate random 'X' and 'O' data in the 2D array
    void generateRandomData() {
        srand(time(0));

        // Allocating memory for the 2D array
        dataContainer = new char*[m_Height];
        for (int i = 0; i < m_Height; ++i) {
            dataContainer[i] = new char[m_Width];
        }

        // Filling the array with random 'X' and 'O' values
        for (int i = 0; i < m_Height; ++i) {
            for (int j = 0; j < m_Width; ++j) {
                int randomValue = rand() % 2;
                dataContainer[i][j] = (randomValue == 0) ? 'X' : 'O';
            }
        }
    }

    // Method to display the generated data
    void displayData() {
        cout << "Generated data in the container:" << endl;
        for (int i = 0; i < m_Height; ++i) {
            for (int j = 0; j < m_Width; ++j) {
                cout << dataContainer[i][j] << " ";
            }
            cout << endl;
        }
    }

private:
    int m_Width; // Attribute to store the width of the video
    int m_Height; // Attribute to store the height of the video
    char **dataContainer; // 2D array to store 'X' and 'O' data
};

int main() {
    cout << "TEST2" << endl;
    Frame videoFrame;

    // Defining the width and height of the video
    int width = videoFrame.defineWidth();
    int height = videoFrame.defineHeight();

    // Generating random 'X' and 'O' data
    videoFrame.generateRandomData();

    // Displaying the generated data
    videoFrame.displayData();

    return 0;
}

