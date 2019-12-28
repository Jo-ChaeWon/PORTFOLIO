void setup()
{
  size(1000, 600);
  rectMode(CENTER);
  }

int x = 500;
int y = 300;
int x_speed = 5;
int y_speed = 5;
int x_paddle = 60;
int y_paddle = 250;
int x_paddle2 = 925;
int y_paddle2 = 250;
int paddle_width_half = 50;
int score = 0;
int score2 = 0;

void draw(){
  x=x+x_speed;
  y=y+y_speed;
  
  if(y<0||y>600){
    y_speed = -y_speed;
  }
  
  if(keyPressed){
    if(key=='w'){
      y_paddle=y_paddle-8;
    } else if(key=='s'){
      y_paddle=y_paddle+8;
    } else if(key==' '){
      x = 500;
      y = 300;
      y_paddle = 250;
      y_paddle2 = 250;
    }
  }
  
  if(y_paddle>600)
    y_paddle=600;
  if(y_paddle<0)
    y_paddle=0;
      
  if((y_paddle-paddle_width_half)<y && (y_paddle+paddle_width_half)>y && (x_paddle-14)<x && (x_paddle)>x){
    x_speed = -x_speed;
  }
  background(0);
  
  fill(0, 255, 0);
  ellipse(x, y, 20, 20);
  fill(255, 255, 120);
  rect(x_paddle, y_paddle, 15, paddle_width_half*2+1);
  
  if(keyPressed){
    if(keyCode==UP){
      y_paddle2=y_paddle2-8;
    } else if(keyCode==DOWN){
      y_paddle2=y_paddle2+8;
    }
  }
  if((y_paddle2-paddle_width_half)<y && (y_paddle2+paddle_width_half)>y && (x_paddle2-14)<x && (x_paddle2)>x){
    x_speed = -x_speed;
  }
    if(y_paddle2>600)
    y_paddle2=600;
  if(y_paddle2<0)
    y_paddle2=0;
  
  fill(255, 255, 120);
  rect(x_paddle2, y_paddle2, 15, paddle_width_half*2+1);
  
  if(x>990){
    x=-x_speed;
    score = score+1;
    x=500;
    y=300;
  } else if(x<10){
    x=-x_speed;
    score2 = score2+1;
    x=500;
    y=300;
  }
  
  textSize(16);
  textAlign(LEFT);
  text(score, 60, 60);
  textAlign(RIGHT);
  text(score2, 940, 60);
}
