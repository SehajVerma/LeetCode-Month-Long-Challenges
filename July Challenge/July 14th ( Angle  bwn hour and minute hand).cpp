class Solution {
public:
    double angleClock(int hour, int min) {
//         if(min==0)
//             return (hour%12)*30;
//         int hr = hour;
//         int x = min - (min/5)*5;

//         double angle = (abs(min/5 - hr%12 ))* 30;
//         if(angle==0)
//             return abs(x*6-(float)min/2);
//         if(min<5)
//             angle -=x*6;
//         else
//             angle +=x*6;
     
//         double ang =  (float)min/2;
//         if(hour==12 || hour*5<min)
//             angle -= ang;
//         else
//             angle +=ang;
//         if(angle<(360-angle))
//             return angle;
//         else
//             return 360-angle;
     float h = (hour%12 + (float)min/60)*30;
     float m = min*6;
     float angle = fabs(h-m);
     if(angle>180) 
         return 360-angle;
        else
            return angle;
    }
};
