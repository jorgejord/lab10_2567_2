#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main (){
	ifstream source;
	ofstream dest;
	source.open("cheerbook.txt") ;
	dest.open("cheerbook_copy.txt");
	
	//Version ส่งงานเพราะ Web มันมี if กับ cout ที่เสร็มไปขก.คอมเม้นเลยทำอีก Version
	//กรอก Code เฉพาะส่วนนี้ ให้สอดคล้องกับโจทย์และ Code ส่วนอื่น ๆ 
	//โดยห้ามแก้ไข Code ในส่วนอื่น ๆ
	dest << "-------------------- BOOM ---------------------" << endl;
	string line;	
	while(getline(source,line)){
		dest << line <<"\n";
	}
	dest << "-------------------- HA!! ---------------------" << endl;
    source.close();
    dest.close();
	return 0;
}



	//Version ใช้เอง

	// กันไปโดนไฟล์อื่นถ้าเปิดถูกก็ทำงานปกติแหละ
    // if (source.is_open() && dest.is_open()) {
    //     // เพิ่มข้อความบรรทัดแรก
    //     dest << "-------------------- BOOM ---------------------" << endl;

    //     // อ่านข้อมูลไฟล์ต้นฉบับและคัดลอกจนบรรทัดสุดท้าย
    //     string line;
    //     while (getline(source, line)) {
    //         dest << line << endl;
    //     }

    //     // เพิ่มข้อความบรรทัดสุดท้าย
    //     dest << "-------------------- HA!! ---------------------" << endl;

	// 	//check ใน terminal ว่ามันได้ทำงานมั้ย(ไม่มีผลในไฟล์txt)
    //     cout << "คัดลอกและเพิ่มข้อความสำเร็จ!" << endl;
    // } else {
	// 	//check ใน terminal ว่ามันได้ทำงานมั้ย(ไม่มีผลในไฟล์txt)
    //     cout << "ไม่สามารถเปิดไฟล์ได้!" << endl;
    // }


//     source.close();
//     dest.close();
// 	return 0;
// }
