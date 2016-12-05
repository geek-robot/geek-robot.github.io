

float a=0; float mx=0; float my=0;
PFont f;

void setup() {
  size(860,440);         
  background(0);
  fill(204,102,0);
  rect(20,20,400,400);
  fill(204,102,0);
  rect(440,20,400,400);
     
  stroke(255);
  strokeWeight(2);
  
  line(40,40,40,400);
  line(40,40,400,40);
  line(400,40,400,200);
  line(400,200,300,200);
  line(300,200,300,300);
  line(300,300,200,300);
  line(200,300,200,400);
  line(200,400,40,400);
  line(150,150,200,150);
  line(200,150,200,200);
  line(200,200,150,200);
  line(150,200,150,150);
  
  printArray(PFont.list());
  f = createFont("Georgia", 15);
  textFont(f);
   text("Map Explored by the BOT", 650, 435);
   text("BOT - mapping and navigation", 30, 435);
   text("Self-Localized Autonomous Mapping System", 300, 435);
  
  smooth();
}

void draw() {
 
  
  if (mousePressed){
  strokeWeight(2);
  beginShape(POINTS);
  
  for (int a = 0; a < 360; a+=6) {
    float angle = radians(a);
    mx = mouseX + cos(angle) * 40;
    my = mouseY + sin(angle) * 40;
  
 
 
  if(mouseX>50 && mouseX<150 && mouseY>50 && mouseY<140){ //box 1
  noStroke();
  ellipse(mouseX,mouseY, 80, 80);
  fill(204, 153, 0,10);
  stroke(225);
  color(12,144,1);
  rect(mouseX-5,mouseY-5,10,10);

  if(mx<=40){ mx=40; vertex(mx+420, my);}
  else if(my<=40){ my=40; vertex(mx+420, my);}
  else vertex(mx,my);

  
}

else if(mouseX>150 && mouseX<200 && mouseY>50 && mouseY<140){ //box2
  noStroke();
  ellipse(mouseX,mouseY, 80, 80);
  fill(204, 153, 0,5);
  stroke(225);
  color(12,144,1);
  rect(mouseX-5,mouseY-5,10,10);


  if(my>=150){ my=150; vertex(mx+420, my);} 
  else if(my<=40){ my=40; vertex(mx+420, my);}
  else vertex(mx,my);
} 

 else if(mouseX>200 && mouseX<390 && mouseY>50 && mouseY<140){ //box3
 noStroke();
  ellipse(mouseX,mouseY, 80, 80);
  fill(204, 153, 0,5);
  stroke(225);
  color(12,144,1);
  rect(mouseX-5,mouseY-5,10,10);


  if(mx>=400){ mx=400; vertex(mx+420, my);} 
  else if(my<=40){ my=40; vertex(mx+420, my);}
  else vertex(mx,my);
 }
 

else if(mouseX>300 && mouseX<390 && mouseY>50 && mouseY<190){ //box4
 noStroke();
  ellipse(mouseX,mouseY, 80, 80);
  fill(204, 153, 0,5);
  stroke(225);
  color(12,144,1);
  rect(mouseX-5,mouseY-5,10,10);


  if(mx>=400){ mx=400; vertex(mx+420, my);} 
 // else if(mx<=200){ mx=200; vertex(mx+420, my);}
  else if(my>=200){ my=200; vertex(mx+420, my);}
  else vertex(mx,my);
}

else if(mouseX>210 && mouseX<300 && mouseY>50 && mouseY<190){ //box5
 noStroke();
  ellipse(mouseX,mouseY, 80, 80);
  fill(204, 153, 0,5);
  stroke(225);
  color(12,144,1);
  rect(mouseX-5,mouseY-5,10,10);

  if(mx<=200){ mx=200; vertex(mx+420, my);}
  else vertex(mx,my);
}

else if(mouseX>210 && mouseX<300 && mouseY>200 && mouseY<300){ //box6
  noStroke();
  ellipse(mouseX,mouseY, 80, 80);
  fill(204, 153, 0,5);
  stroke(225);
  color(12,144,1);
  rect(mouseX-5,mouseY-5,10,10);

  if(mx>=300){ mx=300; vertex(mx+420, my);}
  else if(my>=300){ my=300; vertex(mx+420, my);}
  else vertex(mx,my);
}
  
  else if(mouseX>150 && mouseX<200 && mouseY>200 && mouseY<300){ //box7
  noStroke();
  ellipse(mouseX,mouseY, 80, 80);
  fill(204, 153, 0,5);
  stroke(225);
  color(12,144,1);
  rect(mouseX-5,mouseY-5,10,10);

  if(my<=200){ my=200; vertex(mx+420, my);}  
  else vertex(mx,my);
}

  else if(mouseX>50 && mouseX<150 && mouseY>200 && mouseY<300){ //box8
  noStroke();
  ellipse(mouseX,mouseY, 80, 80);
  fill(204, 153, 0,5);
  stroke(225);
  color(12,144,1);
  rect(mouseX-5,mouseY-5,10,10);

  if(mx<=40){ mx=40; vertex(mx+420, my);}  
  else vertex(mx,my);
}

 else if(mouseX>50 && mouseX<140 && mouseY>150 && mouseY<200){ //box9
  noStroke();
  ellipse(mouseX,mouseY, 80, 80);
  fill(204, 153, 0,5);
  stroke(225);
  color(12,144,1);
  rect(mouseX-5,mouseY-5,10,10);

  if(mx>=150){ mx=150; vertex(mx+420, my);}  
  else if(mx<=40){ mx=40; vertex(mx+420, my);}
  else vertex(mx,my);
}

 else if(mouseX>50 && mouseX<190 && mouseY>300 && mouseY<390){ //box10
  noStroke();
  ellipse(mouseX,mouseY, 80, 80);
  fill(204, 153, 0,5);
  stroke(225);
  color(12,144,1);
  rect(mouseX-5,mouseY-5,10,10);

  if(mx>=200){ mx=200; vertex(mx+420, my);}  
  else if(mx<=40){ mx=40; vertex(mx+420, my);}
  else if(my>=400){ my=400; vertex(mx+420, my);}
  else vertex(mx,my);
}

  
  }
 endShape();}

}
 