#include<iostream>
using namespace std;

int main(){
	int count[5] = {0,0,0,0,0}; //Declare array count for counting A,B,C,D,F and initialize all element = 0
	int totalStudens = 0; //นับจำนวนนักเรียน
	char grade; //กำหนดค่า grade

	cout << "Please input grade of each student (A-F) or input 0 to exit." << endl;
	
	do{
		cout << "Student [" << totalStudens + 1 << "]: ";
		cin >> grade; 
		
		if (grade == '0'){//The loop must be terminated when grade = '0'
			break;//ออกโปรแกรมเลย
		}

		if(grade == 'A') { // if grade is A
			count[0]++; //นับในช่องแรกของ array +1
			totalStudens++; //นับในตัวแปร totalStuden +1
		}else if(grade == 'B'){
			count[1]++;
			totalStudens++;
		}else if(grade == 'C'){
			count[2]++;
			totalStudens++;
		}else if(grade == 'D'){
			count[3]++;
			totalStudens++;
		}else if(grade == 'F'){
			count[4]++;
			totalStudens++;
		}else{
			cout << "Wrong input. Please input again." << endl;
		}
	}while(true);
	
	
	cout << "In total " << totalStudens << " students." << endl;
	cout << "A = " << count[0] << ", "; //พิม A = เอาค่าจาก array ช่องแสดงค่าออกมา แล้วเขียน , เพื่อให้แยกของแต่ละข้อ
	cout << "B = " << count[1] << ", ";
	cout << "C = " << count[2] << ", ";
	cout << "D = " << count[3] << ", ";
	cout << "F = " << count[4] << endl;
	
	return 0;
}