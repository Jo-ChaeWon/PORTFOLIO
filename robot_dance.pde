int armAngle = 0;
int angleChange = 5;
int legAngle = 0;
int angleCha = 5;
final int ANGLE_LIMIT = 135;
final int ANGLE_LIT = 135;

void setup()
{
  size(200, 200);
  smooth();
  frameRate(30);
}

void draw()
{
  background(255);
  pushMatrix();
  translate(50, 50); // place robot so arms are always on screen
  drawRobot();
  armAngle += angleChange;
  
  // if the arm has moved past its limit,
  // reverse direction and set within limits.
  if (armAngle > ANGLE_LIMIT || armAngle < 0)
  {
    angleChange = -angleChange;
    armAngle += angleChange;
  }
  popMatrix();
  
  pushMatrix();
  translate(50, 50);
  legAngle += angleCha;
  
  if (legAngle > ANGLE_LIT || legAngle < 0)
  {
    angleCha = -angleCha;
    legAngle += angleCha;
  }
  popMatrix();
}


void drawRobot()
{
  noStroke();
  fill(38, 38, 200);
  rect(20, 0, 38, 30); // head
  rect(14, 32, 50, 50); // body
  
  drawLeftArm();
  drawRightArm();
  rect(-8, 32, 20, 13); // left arm
  rect(66, 32, 20, 13); // right arm
  
  drawLeftLeg();
  drawRightLeg();
  rect(18, 84, 16, 25); // left leg
  rect(44, 84, 16, 25); // right leg
  
  fill(222, 222, 249);
  ellipse(30, 12, 12, 12); // left eye
  ellipse(47, 12, 12, 12);  // right eye
  
}

void drawLeftArm()
{
  pushMatrix();
  translate(-11, 32);
  rotate(radians(armAngle));
  rect(-20, 0, 20, 12); // left arm
  popMatrix();
}


void drawRightArm()
{
  pushMatrix();
  translate(88, 32);
  rotate(radians(-armAngle));
  rect(0, 0, 20, 12); // right arm
  popMatrix();
}

void drawLeftLeg()
{
  pushMatrix();
  translate(18, 110);
  rotate(radians(armAngle));
  rect(0, 0, 16, 25); // left leg
  popMatrix();
}

void drawRightLeg()
{
  pushMatrix();
  translate(57, 112);
  rotate(radians(-armAngle));
  rect(-12, 0, 16, 25); // right leg
  popMatrix();
}
