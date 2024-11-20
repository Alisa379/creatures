#include <iostream>
#include <fstream>
#include <unistd.h>
#include <cstdlib>
int main(int argc, char** argv) {    
	int w, h, gen=1, cells = 0, deffrence=1;           
	std::ifstream file("D:\\c++\\new2.txt");     
	file >> w;    
	file >> h;   
	char field [h][w];    
	
	for (int i=0; i<h; ++i) {                  // создаём массив
 		for (int j=0; j<w; ++j) {            
  			field[i][j]='-';        
 		}    
	}
	
	while (file) {                             // населяем массив
 	int i, j;        
 	file >> i;
 	if (file.eof()) {
 		break;
	}
	file >> j;        
 	field[i][j]='*';       
 	cells+=1;
	}
	     
	for (int i=0; i<h; ++i) {                   // выводим массивчик
		for (int j=0; j<w; ++j) {           
  			std::cout<<field[i][j]<<" ";        
 		}        
 	std::cout<<std::endl;    
	}  
	        
	while (cells != 0) {                                               // началось обновление
	
		std::cout<<"Generation: "<<gen<<". Alive cells: "<<cells<<std::endl;
		
		if (deffrence == 0) {
			std::cout<<"The world has stagnated. Game over";
			return 0;
		}  
		gen++;
 		int birth = 0, neighbours = 0;
 		deffrence = 0;
 		std::fstream fcdel("del.txt", std::ios::app);
 		std::fstream fcadd("add.txt", std::ios::app);
 		for (int i=1; i<h-1; ++i) {                                      // проход по серединке
  			for (int j=1; j<w-1; ++j) {
   			if (field[i-1][j-1]=='*') {
     				neighbours++;
   			} 
   			if (field[i-1][j]=='*') {
   				neighbours++;
   			} 
   			if (field[i-1][j+1]=='*') {
   				neighbours++;
   			} 
   			if (field[i][j-1]=='*') {
   				neighbours++;
   			} 
   			if (field[i][j+1]=='*') {
   				neighbours++;
   			} 
   			if (field[i+1][j-1]=='*') {
   				neighbours++;
   			} 
   			if (field[i+1][j]=='*') {
   				neighbours++;
   			} 
   			if (field[i+1][j+1]=='*') {
   				neighbours++;
   			}
   			if (neighbours!=2 && neighbours!=3) {
   				fcdel << i << " ";
   				fcdel << j << "\n";
				}
				if (neighbours == 2 && field[i][j]=='*') {
					fcadd << i << " ";
					fcadd << j << "\n";
					birth++;
			   }
				if (neighbours == 2 && field[i][j]=='-') {
					fcdel << i << " ";
					fcdel << j << "\n";
				}
				if (neighbours==3) {
					fcadd << i << " ";
					fcadd << j << "\n";
					birth++;
				}
   	      neighbours = 0;
  			} 
 		}
 		
 		for (int j=1; j<w-1; ++j) {                           // проход по верхней части
 			if (field[0][j-1]=='*') {
   			neighbours++;
   		}
   		if (field[1][j-1]=='*') {
   			neighbours++;
   		}
   		if (field[1][j]=='*') {
   			neighbours++;
   		}
   		if (field[1][j+1]=='*') {
   			neighbours++;
   		}
   		if (field[0][j+1]=='*') {
   			neighbours++;
   		}
   		if (neighbours!=2 && neighbours!=3) {
   			fcdel << 0 << " ";
   			fcdel << j << "\n";
			}
			if (neighbours == 2 && field[0][j]=='*') {
				fcadd << 0 << " ";
				fcadd << j << "\n";
				birth++;
			}
			if (neighbours == 2 && field[0][j]=='-') {
				fcdel << 0 << " ";
				fcdel << j << "\n";
			}
			if (neighbours==3) {
				fcadd << 0 << " ";
				fcadd << j << "\n";
				birth++;
		   }
   	   neighbours = 0;
		} 
		   
		for (int j=1; j<w-1; ++j) {                           // проход по нижней части
 			if (field[h-1][j-1]=='*') {
   			neighbours++;
   		}
   		if (field[h-2][j-1]=='*') {
   			neighbours++;
   		}
   		if (field[h-2][j]=='*') {
   			neighbours++;
   		}
   		if (field[h-2][j+1]=='*') {
   			neighbours++;
   		}
   		if (field[h-1][j+1]=='*') {
   			neighbours++;
   		}
   		if (neighbours!=2 && neighbours!=3) {
   			fcdel << h-1 << " ";
   			fcdel << j << "\n";
			}
			if (neighbours == 2 && field[h-1][j]=='*') {
				fcadd << h-1 << " ";
				fcadd << j << "\n";
				birth++;
			}
			if (neighbours == 2 && field[h-1][j]=='-') {
				fcdel << h-1 << " ";
				fcdel << j << "\n";
			}
			if (neighbours==3) {
				fcadd << h-1 << " ";
				fcadd << j << "\n";
				birth++;
			}
   	   neighbours = 0;
		}
		 
		for (int i=1; i<h-1; ++i) {                // проход по левой части
			if (field[i-1][0]=='*') {
   			neighbours++;
   		}
   		if (field[i-1][1]=='*') {
   			neighbours++;
   		}
   		if (field[i][1]=='*') {
   			neighbours++;
   		}
   		if (field[i+1][1]=='*') {
   			neighbours++;
   		}
   		if (field[i+1][0]=='*') {
   			neighbours++;
   		}
   		if (neighbours!=2 && neighbours!=3) {
   			fcdel << i << " ";
   			fcdel << 0 << "\n";
			}
			if (neighbours == 2 && field[i][0]=='*') {
				fcadd << i << " ";
				fcadd << 0 << "\n";
				birth++;
			}
			if (neighbours == 2 && field[i][0]=='-') {
				fcdel << i << " ";
				fcdel << 0 << "\n";
			}
			if (neighbours==3) {
				fcadd << i << " ";
				fcadd << 0 << "\n";
				birth++;
			}
   	   neighbours = 0;
		}
		
		for (int i=1; i<h-1; ++i) {                // проход по правой части
			if (field[i-1][w-1]=='*') {
   			neighbours++;
   		}
   		if (field[i-1][w-2]=='*') {
   			neighbours++;
   		}
   		if (field[i][w-2]=='*') {
   			neighbours++;
   		}
   		if (field[i+1][w-2]=='*') {
   			neighbours++;
   		}
   		if (field[i+1][w-1]=='*') {
   			neighbours++;
   		}
   		if (neighbours!=2 && neighbours!=3) {
   			fcdel << i << " ";
   			fcdel << w-2 << "\n";
			}
			if (neighbours == 2 && field[i][w-1]=='*') {
				fcadd << i << " ";
				fcadd << w-1 << "\n";
				birth++;
			}
			if (neighbours == 2 && field[i][w-1]=='-') {
				fcdel << i << " ";
				fcdel << w-1 << "\n";
			}
			if (neighbours==3) {
				fcadd << i << " ";
				fcadd << w-1 << "\n";
				birth++;
			}
   	   neighbours = 0;
   	}
   	
   	if (field[0][1] == '*') {                   // проход по левому верхнему краю
   		neighbours++;
		}
		if (field[1][1] == '*') {                   
   		neighbours++;
		}
		if (field[0][1] == '*') {                   
   		neighbours++;
		}
		if (neighbours!=2 && neighbours!=3) {
   		fcdel << 0 << " ";
   		fcdel << 0 << "\n";
		}
		if (neighbours == 2 && field[0][0]=='*') {
			fcadd << 0 << " ";
			fcadd << 0 << "\n";
			birth++;
		}
		if (neighbours == 2 && field[0][0]=='-') {
			fcdel << 0 << " ";
			fcdel << 0 << "\n";
		}
		if (neighbours==3) {
			fcadd << 0 << " ";
			fcadd << 0 << "\n";
			birth++;
		}
   	neighbours = 0;
   	
   	if (field[h-2][0] == '*') {                   // проход по левому нижнему краю
   		neighbours++;
		}
		if (field[h-2][1] == '*') {                   
   		neighbours++;
		}
		if (field[h-1][1] == '*') {                   
   		neighbours++;
		}
		if (neighbours!=2 && neighbours!=3) {
   		fcdel << h-1 << " ";
   		fcdel << 0 << "\n";
		}
		if (neighbours == 2 && field[h-1][0]=='*') {
			fcadd << h-1 << " ";
			fcadd << 0 << "\n";
			birth++;
		}
		if (neighbours == 2 && field[h-1][0]=='-') {
			fcdel << h-1 << " ";
			fcdel << 0 << "\n";
		}
		if (neighbours==3) {
			fcadd << h-1 << " ";
			fcadd << 0 << "\n";
			birth++;
		}
   	neighbours = 0;
   	
   	if (field[0][w-2] == '*') {                   // проход по правому верхнему краю
   		neighbours++;
		}
		if (field[1][w-2] == '*') {                   
   		neighbours++;
		}
		if (field[1][w-1] == '*') {                   
   		neighbours++;
		}
		if (neighbours!=2 && neighbours!=3) {
   		fcdel << 0 << " ";
   		fcdel << w-1 << "\n";
		}
		if (neighbours == 2 && field[0][w-1]=='*') {
			fcadd << 0 << " ";
			fcadd << w-1 << "\n";
			birth++;
		}
		if (neighbours == 2 && field[0][w-1]=='-') {
			fcdel << 0 << " ";
			fcdel << w-1 << "\n";
		}
		if (neighbours==3) {
			fcadd << 0 << " ";
			fcadd << w-1 << "\n";
			birth++;
		}
   	neighbours = 0;
   	
   	if (field[h-2][w-1] == '*') {                   // проход по правому нижнему краю
   		neighbours++;
		}
		if (field[h-2][w-2] == '*') {                   
   		neighbours++;
		}
		if (field[h-1][w-2] == '*') {                   
   		neighbours++;
		}
		if (neighbours!=2 && neighbours!=3) {
   		fcdel << h-1 << " ";
   		fcdel << w-1 << "\n";
		}
		if (neighbours == 2 && field[h-1][w-1]=='*') {
			fcadd << h-1 << " ";
			fcadd << w-1 << "\n";
			birth++;
		}
		if (neighbours == 2 && field[h-1][w-1]=='-') {
			fcdel << h-1 << " ";
			fcdel << w-1 << "\n";
		}
		if (neighbours==3) {
			fcadd << h-1 << " ";
			fcadd << w-1 << "\n";
			birth++;
		}
		
		cells = birth;
		
		fcdel.close();
		std::ifstream deathfile1("del.txt");
		while (deathfile1) {
			int i, j;
			deathfile1 >> i;
			if (deathfile1.eof()) {
 				break;
			}
			deathfile1 >> j;
			if (field[i][j] == '*') {
				deffrence++;
			}
		}
		
		fcadd.close();
		std::ifstream alivefile1("add.txt");
		while (alivefile1) {
			int i, j;
			alivefile1 >> i;
			if (alivefile1.eof()) {
 				break;
			}
			alivefile1 >> j;
			if (field[i][j] == '-') {
				deffrence++;
			}
   	}
		deathfile1.close();                               // заполняем мир нежевыми клетками
		std::ifstream deathfile("del.txt");
 		while (deathfile) {                             
 			int i, j;        
 			deathfile >> i;
 			if (deathfile.eof()) {
 				break;
			}
			deathfile >> j;        
 			field[i][j]='-';
		}
		
		
		alivefile1.close();                                // заполняем мир живыми клетками
		std::ifstream alivefile("add.txt");
 		while (alivefile) {                             
 			int i, j;        
 			alivefile >> i;
 			if (alivefile.eof()) {
 				break;
			}
			alivefile >> j;        
 			field[i][j]='*';    
		}
		
		
		
		
		sleep(0);
		std::system("pause");
		std::system("cls");
		
		for (int i=0; i<h; ++i) {
			for (int j=0; j<w; ++j) {
				std::cout<<field[i][j]<<" ";
			}
			std::cout<<std::endl;
		}
		
		
		deathfile.close();
		std::remove("del.txt");
		alivefile.close();
		std::remove("add.txt");
	}
	  
	std::cout<<"Generation: "<<gen<<". Alive cells: "<<cells<<std::endl;    
	std::cout<<"All cells are dead. Game over";    
}