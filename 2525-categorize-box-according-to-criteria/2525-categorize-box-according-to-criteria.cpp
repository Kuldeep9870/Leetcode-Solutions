class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool heavy=false;
        bool bulky =false;
        //cout<<length*width*height;
        if(mass>=100)
            heavy=true;
        if(length >=10000 || width>=10000 || height>=10000){
            bulky=true;
        }
        else if( 1LL*length*width*height>=1000000000)
            bulky=true;
        
        if(heavy && bulky){
            return "Both";
        }
        else if(heavy && !bulky){
            return "Heavy";
        }
        else if(!heavy && bulky){
            return "Bulky";
        }
        else{
            return "Neither";
        }
    }
};