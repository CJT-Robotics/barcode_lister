#include <ros/ros.h>
#include <std_msgs/String.h>
#include <string>
#include <unordered_set>
#include <fstream>

using namespace std;

#define FILE_PATH "src/barcode_lister/barcode.txt"

unordered_set<string> filter;
ofstream file;


void onBarcodeReceive(const std_msgs::String::ConstPtr& msg)
{

    string link = msg->data.c_str();
    cout << link << endl;
    cout << 234 << endl;
    if(filter.count(link) == 0){
        cout << link << "345" << endl;
        file << link << "\n";      
        filter.insert(link);
    }
    
}

int main(int argc, char **argv)
{

  file.open(FILE_PATH, std::ios_base::app);
  
  ros::init(argc, argv, "cjt_barcode_listener");

  ros::NodeHandle n;

    cout << 456 << endl;
  ros::Subscriber sub = n.subscribe("/cjt/barcode", 1, onBarcodeReceive);

  
  ros::spin();
    file.close();
  return 0;
}