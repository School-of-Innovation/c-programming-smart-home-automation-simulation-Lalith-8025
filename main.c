/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */

#include <stdio.h>

#define MAX_ROOMS 5  //  max number of rooms

int lights[MAX_ROOMS];
int temp[MAX_ROOMS];
int motion[MAX_ROOMS];
int security[MAX_ROOMS];

// Function prototypes
void initializeSystem();
void displayMenu();
void controlLights();
void readTemperature();
void detectMotion();
void securitySystem();
void analyzeHouseStatus();

int main() {
    initializeSystem();
    while (1){
        displayMenu();
    } 
    return 0;
}

 
void initializeSystem() {
    for(int i=0;i<MAX_ROOMS;i++){
        lights[i]=0;  //intialised lights in off condition
        temp[i]=25;   //default temp is set to 25
        motion[i]=0;  // intialized no motion detection
        security[i]=1; // initialised rooms locked
    }
    printf("Initializing system...\n");
  
}

void displayMenu() {
    int choice;
    printf("==== Smart home Menu ====\n");
    printf("1. Toggle Lights\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Detection\n");
    printf("4. Security Systems\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
    printf("ENTER YOUR CHOICE\n");
    scanf("%d",&choice);
    
    switch (choice){
        case 1:
        controlLights();
        break;

        case 2:
        readTemperature();
        break;

        case 3:
        detectMotion();
        break;

        case 4:
        securitySystem();
        break;

        case 5:
        analyzeHouseStatus();
        break;

        case 6:
        printf("Exiting....\n");
    
    default:
        printf("Invalid Choice \n");
    }
   
}
void controlLights() {
    int room;
    printf("Enter the room number to toggle light (1-5)\n");
    scanf("%d",&room);

    if(room>=1 && room<=MAX_ROOMS){
        if (lights[room-1]==0){
            lights[room-1]=1;
            printf("Light in Room %d is now ON\n",room);
        }
        else{
            lights[room-1]=0;
            printf("Light in Room %d is now OFF\n",room);
        }
    }
    else{
        printf("Invalid room number!!! \n");
    }

}
void readTemperature() {
    int room;
    printf("Enter the room number to read temperature (1-5)\n");
    scanf("%d",&room);

    if(room>=1 && room<=MAX_ROOMS){
        printf("Temperature in the room %d is %d *C \n",room,temp[room-1]);
    }
    else{
        printf("Invalid Room number!!! \n");
    }

}
void detectMotion() {
    for(int i=0;i<MAX_ROOMS;i++){
        if(motion[i]==1){
            printf("Motion Detected in the room %d",i+1);
        }
        else{
            printf("There is no Motion detected in the room %d",i+1);
        }
    }

}
void securitySystem() {
    for(int i=0;i<MAX_ROOMS;i++){
        if(security[i]==1){
            printf("Room %d is locked",i+1);
        }
        else{
            printf("Room %d is unlocked",i+1);
        }
    }
    
    int room;
    printf("Enter the room number to lock or unlock (1-5)\n");
    scanf("%d",&room);

    if (room>=1 && room <=MAX_ROOMS){
        if (security[room-1]==1){
            security[room-1]=0;
            printf("Room %d is now unlocked\n",room);
        }
        else{
            security[room-1]=1;
            printf("Room %d is now locked\n",room);
        }
    }
    else{
        printf("Invalid room number!!!\n");
    }

}
void analyzeHouseStatus() {
    printf("House Status:\n");
    for(int i=0;i<MAX_ROOMS;i++){
        printf("Room %d ", i+1);
        if (lights[i]==1){
            printf("Lights ON,");
        }
        else{
            printf("Lights OFF,");
        }
        
        printf("Temp %d *C ", temp[i]);
        
        
        if (motion[i]==1){
            printf("Motion Detected,");
        }
        else{
            printf("No Motion Detected,");
        }

        if (security[i]==1){
            printf("Locked\n");
        }
        else{
            printf("Unlocked\n");
        }
    }
}
