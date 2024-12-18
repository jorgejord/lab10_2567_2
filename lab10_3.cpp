//cout << "Number of data = ";
//cout << "Mean = ";
//cout << "Standard deviation = ";

// Version 1

// #include <iostream>
// #include <fstream>
// #include <cmath>
// #include <iomanip>
// #include <string>
// using namespace std;

// int main(){
//     ifstream source; // สร้างตัวแปรชื่อว่า source เพื่อจะเอามาอ่านข้อมูลจากไฟล์
//     source.open("score.txt"); // ชื่อตัวแปร .เปิด เพื่อเปิดไฟล์("score.txt");
//     string line ; // เก็บข้อความแต่ละบรรทัด ( line คือตัวแปรเดอกันลืม)
//     double mew,SD,num,sum = 0.0,sum_2 = 0.0; // ประกาศตัวแปรเป็น double จะเพราะต้องใช้ค่าทศนิยม
//     int n = 0; // นับจำนวนข้อมูลเฉยๆ
//     while(getline(source,line)){ // อ่านไฟล์แต่ละบรรทัดแล้วเก็บค่าในตัวแปร line
//         // num =  atof(textline.c_str()) ; ใช้ได้คล้ายๆกันแต่กันใส่ abc ละมันจะล่ม
//         num = std::stod(line); // แปลงข้อความเป็นตัวเลข
//         sum += num; // รวมตัวเลขทั้งหมด
//         sum_2 += num*num; //รวมเหมือนกันแต่เพิ่มกำลัง 2
//         n++; // เพิ่มตัวนับจำนวนข้อมูล n + 1
//     }

//     mew = 1.0/n*sum; // ค่าเฉลี่ย = ผลรวมตัวเลขทั้งหมด (sum) หารจำนวนข้อมูล (n)
//     SD = sqrt((1.0/n*sum_2)-pow(mew,2)); // ส่วนเบี่ยงเบนมาตรฐานจากสูตร
//     cout << "Number of data = "<< n <<endl; // แสดงจำนวนนับ n
//     cout << setprecision(3); // กำหนดค่าทศนิยม 3 ตำแหน่ง
//     cout << "Mean = " << mew << endl; // แสดงค่าเฉลี่ย
//     cout << "Standard deviation = "<< SD << endl; // แสดงค่าเบี่ยงเบนมาตรฐาน
// }


// Version 2

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    ifstream source("score.txt"); // เรียกscore.txtโดยตรง
    if (!source) { // เช็คว่าเปิดไฟล์ได้ป่าว
        cerr << "Error: Cannot open file.\n"; // cerr คือแสดงข้อผิดพลาด
        return 1;
    }

    double sum = 0.0, sum_2 = 0.0, num;
    int n = 0;
    string line;

    while (getline(source, line)) {
        try { // ใช้ try-catch แทนเพราะอะไรไปอ่านข้างล่าง
            num = stod(line);
            sum += num;
            sum_2 += num * num;
            n++;
        } catch (const invalid_argument&) { // เพื่อลดข้อผิดพลาดจาก stod เผื่อมีข้อมูลที่แปลงเป็นเลขไม่ได้
            cerr << "Warning: Skipping invalid data - " << line << "\n"; // ข้ามบรรทัดที่ไม่ใช่ตัวเลข
        }
    }

    if (n > 0) { //กันมันเอาไปหาร 0 แบบข้อมูลนี้ว่างไรเงี้ย
        double mean = sum / n; // แก้จาก 1.0 / n * sum เพื่อให้เข้าใจง่ายขึ้น
        double SD = sqrt((sum_2 / n) - pow(mean, 2)); // แก้ให้เข้าใจง่ายขึ้นจากอันเดิม
        cout << "Number of data = " << n << endl;
        cout << setprecision(3) // เพิ่ม fixed ถ้าจะปัดแต่ในนี้ไม่ต้อง
             << "Mean = " << mean << endl
             << "Standard deviation = " << SD << endl;
    } else {
        cout << "No valid data found.\n";
    }
}


