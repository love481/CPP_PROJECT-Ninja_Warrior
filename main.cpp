/* Author:Love Panta
 *email:075bei016.love@pcampus.edu.np
 *date:20,06/2020
 */
#include <SFML/Graphics.hpp>
#include<iostream>
#include<SFML/Audio.hpp>
#include<cstdlib>
#include<ctime>
#include<string>
#include<vector>

sf::RenderWindow window(sf::VideoMode(1000,700), "my project");
class MENU{
private:
    sf::Sprite play,Exit,background;
    sf::Texture pb,eb;
    sf::Font font;
    sf::Text text[3];
public:
    sf::Sprite Play(){
    pb.loadFromFile("start.png");
    play.setTexture(pb);
    play.setScale(0.09,0.09);
    play.setPosition(480,300);
    return play;}
    sf::Sprite EXit()
    {
        eb.loadFromFile("exit.png");
        Exit.setTexture(eb);
        Exit.setScale(0.15,0.15);
        Exit.setPosition(490,425);
        return Exit;
    }
    void TEXT()
    {
        font.loadFromFile("CASTELAR.ttf");
        text[0].setFont(font);
        text[1].setFont(font);
        text[2].setFont(font);
        text[0].setOutlineThickness(3.0f);
        text[1].setOutlineThickness(3.0f);
        text[2].setOutlineThickness(6.0f);
        text[2].setCharacterSize(60.0f);
        text[0].setString("PLAY");
        text[1].setString("EXIT");
        text[2].setString("Warrior Ninja");
        text[0].setPosition(390,335);
        text[1].setPosition(390,435);
        text[2].setPosition(300,150);
        text[0].setColor(sf::Color(125,200,125));
        text[1].setColor(sf::Color(125,200,125));
        text[2].setColor(sf::Color(125,120,125));
        window.draw(text[0]);
        window.draw(text[1]);
        window.draw(text[2]);
    }
};
class BulletV
{ private:
        sf::Sprite bullet;
        int a,b;
  public:
       BulletV(){}
       BulletV(int x,int y)
       {   a=x; b=y;
           sf::Texture bul;
           bul.loadFromFile("love-ball.png");
           bullet.setTexture(bul);
           bullet.setScale(0.8,0.8);
           bullet.setPosition(x,y);
           window.draw(bullet);}
       int getRight()
       {return a+10;}
       int getLeft()
       {return a;}
       int getTop()
       {return b;}
};
class SOUND{
 private:
     sf::Music mu;
 public:
    SOUND(){
     mu.openFromFile("follow.wav");
     mu.setLoop(true);
     mu.setVolume(20.0f);
     mu.play();
     }
};
class shootsound{
 private:
     sf::SoundBuffer sb;
     sf::Sound s,sp;
 public:
     sf::Sound Shootsound(){
     sb.loadFromFile("shoot1.wav");
     s.setBuffer(sb);
     s.setVolume(20.0f);
     return s;
     }
     sf::Sound clicksound()
     {
         sb.loadFromFile("CLIK.wav");
         sp.setBuffer(sb);
         sp.setVolume(100.0f);
         return sp;
     }
};
class Sprite
{ char spR[8][60]={"l-0.png","l-1.png","l-2.png","l-3.png","l-4.png","l-5.png","l-6.png","l-7.png"};
  char spL[8][60]={"l-8.png","l-9.png","l-10.png","l-11.png","l-12.png","l-13.png","l-14.png","l-15.png"};
  sf::Sprite lady;
  sf::Texture texture;
  public:
    void sprite( int x, int y, int walkcountL,int walkcountR,int left=0,int right=0,int standing=0){
          lady.setScale(1,1);
          if(!standing){
            if (left)
            {texture.loadFromFile(spL[walkcountL]);
             lady.move(sf::Vector2f(x,y-5));}
            else if(right){
              texture.loadFromFile(spR[walkcountR]);
              lady.move(sf::Vector2f(x,y));}}
           else{if(left)
              {texture.loadFromFile(spL[0]);
              lady.move(sf::Vector2f(x,y));}
              else{texture.loadFromFile(spR[0]);
              lady.move(sf::Vector2f(x,y));}}
            lady.setTexture(texture);
              window.draw(lady);}
            void check(BulletV bullet,int x,int y,float &s)
            {if((bullet.getRight()>x)&&(bullet.getTop()>535+y)&&(bullet.getTop()+20<585+y)&&(bullet.getLeft()<x+50))
                {lady.setPosition(13456,12455);
                s=s+5;}}
            sf::Sprite anime()
            {
                texture.loadFromFile(spR[0]);
                lady.setTexture(texture);
                lady.setScale(1.20,1.20);
                lady.setPosition(230,140);
                return lady;
            }
};
class healthscore
{ public:
    void health(int x,int y,float decrement)
      {   sf::Texture texture;
          if(decrement<=50)
            {sf::RectangleShape level(sf::Vector2f(80-decrement,10));
             level.setFillColor(sf::Color::Blue);
             level.move(x+70,y);
             window.draw(level);}
          else if(decrement>50&&decrement<=80)
           {sf::RectangleShape level(sf::Vector2f(80-decrement,10));
           level.setFillColor(sf::Color::Red);
           level.move(x+70,y);
           window.draw(level);}}
};
class BulletS
{  private:
     sf::Sprite bullet;
     sf::Texture bul;
   public:
       BulletS(sf::Vector2f Size)
       {bullet.setScale(Size);}
       void fire(int speed,signed int dir){
          if(dir==1)
          {bullet.move(speed, 0);}
          else if(dir==(-1))
          {bullet.move(-speed, 0);}}
       int getRight()
       {return bullet.getPosition().x+10;}
       int getLeft()
       {return bullet.getPosition().x;}
       int getTop()
       {return bullet.getPosition().y;}
       void draw(int right,int left){
           if(right)
           bul.loadFromFile("bulletright.png");
           if(left)
           bul.loadFromFile("bulletleft.png");
           bullet.setTexture(bul);
           window.draw(bullet);}
       void setPos(sf::Vector2f newPos)
       {bullet.setPosition(newPos);}
};
class villain1
{  char spL[11][60]={"L1E.png","L2E.png","L3E.png","L4E.png","L5E.png","L6E.png","L7E.png","L8E.png","L9E.png","L10E.png","L11E.png"};
   char spR[11][60]={"R1E.png","R2E.png","R3E.png","R4E.png","R5E.png","R6E.png","R7E.png","R8E.png","R9E.png","R10E.png","R11E.png"};
   sf::Sprite opposition;
   int i;
  public:
      void sprite1(int x,int y,int walkcount,int vleft,int vright)
          {sf::Texture texture;
          opposition.setScale(1.3,1.15);
          if(vright)
          texture.loadFromFile(spR[walkcount]);
          if(vleft)
          texture.loadFromFile(spL[walkcount]);
          opposition.move(x,y);
          opposition.setTexture(texture);
          window.draw(opposition);}
          void check(BulletS bullet,int x,float &decrease)
             {if((bullet.getRight()>x)&&(bullet.getTop()>535)&&(bullet.getTop()+10<585)&&(bullet.getLeft()<x+50))
                 {opposition.setPosition(12345,12345);
                  decrease+=2.5;}
                 }
};
class background
{   sf::Sprite imagebg,imageplate1[5],imageplate2[5],imageplate3[5];
    sf::Texture t,plate1[5],plate2[5],plate3[5];
   int i,a;
    public:
    background(){}
    background(int &x,int &countbg)
         { a=x;
         for( int i=0;i<5;i++)
         {plate1[i].loadFromFile("draco-plate.png");
         plate2[i].loadFromFile("dread-plate.png");
          plate3[i].loadFromFile("dread-plate.png");
         imageplate1[i].setTexture(plate1[i]);
         imageplate2[i].setTexture(plate2[i]);
         imageplate3[i].setTexture(plate3[i]);}
         window.clear(sf::Color(0,25,25));
           t.loadFromFile("bg.png");
         imagebg.setTexture(t);
         window.draw(imagebg);
         sf::View view;
         view.reset(sf::FloatRect(0,0,1000,700));
         if(x<3700)
         {if(x<1500)
          {a=a+15-(500);
          if(a<0) a=0;
         for(i=0;i<5;i++){
         imageplate1[i].setPosition(500+(i+1)*plate1[i].getSize().x,400);
         imageplate2[i].setPosition(880+(i+1)*plate2[i].getSize().x,250);
         window.draw(imageplate1[i]);
          window.draw(imageplate2[i]);}
          view.reset(sf::FloatRect(a,0,1000,700));}
          else if(x>=1500&&x<2600)
           {
                for(i=0;i<5;i++){
         imageplate1[i].setPosition(680+(i+1)*plate1[i].getSize().x,290);
         imageplate2[i].setPosition(360+(i+3)*plate2[i].getSize().x,290);
         imageplate3[i].setPosition(1000+(i+1)*plate2[i].getSize().x,490);
         window.draw(imageplate1[i]);
          window.draw(imageplate2[i]);
           window.draw(imageplate3[i]);}
          view.reset(sf::FloatRect(x-1500,0,1000,700));}
          else if(x>2600&&x<=3700)
           {view.reset(sf::FloatRect(x-2600,0,1000,700));}
          window.setView(view);}}
};
void villainmotion(int &velocity,int &vleft,int &vright,int &villainwcount,int &villainx)
      {if(velocity>0)
           {vleft=0;
           vright=1;
           villainx+=velocity;
           villainwcount+=1;
           if(villainwcount==10)
           villainwcount=0;
           if (villainx==1000)
              {velocity=-velocity;
               villainwcount=0;}}
           else
              {vleft=1;
               vright=0;
               villainx+=velocity;
               villainwcount+=1;
               if(villainwcount==10)
               villainwcount=0;
               if(villainx==0)
                {velocity=-velocity;
                villainwcount=0;}}
          }
void villainshoot( Sprite &s,int &bulletspeedX,int &bulletspeedY,int villainx,int x,int y,float d1,float d2,float d3,float d4,int vright,int vleft ,float &s1)
            {if(bulletspeedX<=1000){
            if(vright)
            {if(x<1500&&d1<=80)
               {BulletV vbullet(villainx+120+bulletspeedX,550);
               s.check(vbullet,x,y,s1);}
             else if(x>=1500&&x<2600&&d2<=80)
               {BulletV vbullet(villainx+500+25+bulletspeedX,550);
               s.check(vbullet,x-1100,y,s1);}
                else if(x>=2600&&x<3700)
               {  if(d3<=80)
                   {BulletV vbullet(villainx+600+25+bulletspeedX,550);
                s.check(vbullet,x-2200,y,s1);}
                if(d4<=80){
                BulletV v1bullet(villainx+900+25+bulletspeedX,550);
                s.check(v1bullet,x-2200,y,s1);}}
              bulletspeedX+=40;}}
             else
                bulletspeedX=0;
             if(bulletspeedY>=-1000)
             {if(vleft)
             {if(x<1500&&d1<=80)
                {BulletV vbullet(villainx+125+bulletspeedY,550);
                s.check(vbullet,x,y,s1);}
             else if(x>=1500&&x<2600&&d2<=80)
                {BulletV vbullet(villainx+500+25+bulletspeedY,550);
                s.check(vbullet,x-1100,y,s1);}
                 else if(x>=2600&&x<3700)
                { if(d3<=80){
                    BulletV vbullet(villainx+600+25+bulletspeedY,550);
                s.check(vbullet,x-2200,y,s1);}
                 if(d4<=80){
                    BulletV v1bullet(villainx+900+25+bulletspeedY,550);
                s.check(v1bullet,x-2200,y,s1);}
                }
              bulletspeedY-=40;}}
              else
                bulletspeedY=0;
             }
std::vector<BulletS>bulletvectors;
void ladybulletposition(int x,int y,int left,int right,int &press)
          {if(press==1){
             BulletS newbullet(sf::Vector2f(0.03,0.035));
             if(right){
              if(x<=1500)
              {newbullet.setPos(sf::Vector2f(x+70,y+570));}
              else if(x>=1500&&x<=2600)
              newbullet.setPos(sf::Vector2f(x+70-1100,y+570));
              else if(x>=2600&&x<=3700)
              newbullet.setPos(sf::Vector2f(x+70-2200,y+570));}
             else if(left){
              if(x<=1500)
              newbullet.setPos(sf::Vector2f(x,y+570));
              else if(x>=1500&&x<=2600)
              newbullet.setPos(sf::Vector2f(x+25-1100,y+570));
                else if(x>=2600&&x<=3700)
              newbullet.setPos(sf::Vector2f(x+25-2200,y+570));}
              bulletvectors.push_back(newbullet);
              press=0;}
         }
void ladybulleterase(int x,int left ,int right,float &s1,int &villainx)
         {if(s1<=80)
            {for(size_t i=0;i<bulletvectors.size();i++)
              {bulletvectors[i].draw(right,left);
              if(right)
              {bulletvectors[i].fire(100,1);
              if(bulletvectors[i].getRight()>x+700)
              bulletvectors.erase(bulletvectors.begin()+i);}
              else if(left)
              {bulletvectors[i].fire(100,-1);
              if(x<=1500)
              {if(bulletvectors[i].getLeft()<x-500)
              bulletvectors.erase(bulletvectors.begin()+i);}
              else if(x>=1500&&x<=2600)
              {if(bulletvectors[i].getLeft()<x-500-1100)
              bulletvectors.erase(bulletvectors.begin()+i);}
               else if(x>=2600&&x<=3700)
              {if(bulletvectors[i].getLeft()<x-500-2200)
              bulletvectors.erase(bulletvectors.begin()+i);}}}}
          }
void villainbullet_health_lady(villain1 &v,villain1 &v1,healthscore &hv,healthscore &hv1,healthscore &hs,Sprite &s ,int x,int y,float &s1,float &d1,float &d2,float &d3,float &d4,int vleft,int vright, int &villainx,int left,int right,int walkcountL,int walkcountR,int standing,int &villainwcount,int &jump,float &jumpcount,float &Count,bool &block1,bool &block2)
             {
                 if(x<1500)
             {for(size_t i=0;i<bulletvectors.size();i++){
              v.check(bulletvectors[i],villainx+100,d1);}
             if(d1<=80){
             v.sprite1(villainx+100,535,villainwcount,vleft,vright);
             hv.health(villainx+100,535,d1);
             }
             if(s1<=80){
                 if(x>500&&x<870&&y<350){
                 if(jumpcount==0&&y>300){
                 jumpcount=8;
                 jump=0;
                 block1=true;}
                 }
                 else if(block1==true&&jump==0&&y<350&&((x<500)||(x>=870&&x<=880)))
                 {
                     jump=1;
                     Count=11;
                     jumpcount=-9.55;
                     block1=false;
                 }
                 if(x>=900&&x<=1260&&y<=220){
                 if(jumpcount==-6&&y>150){
                 jumpcount=8;
                 jump=0;
                 block2=true;
                 }}
                 else if(block2&&jump==0&&((x>=870&&x<=900)||x>1260))
                 {
                     jump=1;
                     Count=11;
                     jumpcount=-5;
                     block2=false;
                 }
                   if(block2&&jump==0&&(x>500&&x<870))
                 {  jump=1;
                     Count=10;
                     jumpcount=-8;
                     block2=false;
                 }
                  if((Count==11&&int(jumpcount)==-11)||(Count==10&&int(jumpcount)==-10))
                    {
                        jumpcount=8;
                        Count=8;
                        jump=0;
                    }
                if(x>500&&x<870&&y>380)
                {  if(jumpcount==8)
                    {jumpcount=6;
                    Count=6;}
                }
                else if(Count==6&&jumpcount==6)
                {    jumpcount=8;
                    Count=8;
                }
              s.sprite(x,y,walkcountL,walkcountR,left,right,standing);
             hs.health(x,y,s1);
               }}
             else if(x>=1500&&x<2600)
             {for(size_t i=0;i<bulletvectors.size();i++){
              v.check(bulletvectors[i],villainx+500,d2);}
              if(d2<=80)
              {v.sprite1(villainx+500,535,villainwcount,vleft,vright);
              hv.health(villainx+500,535,d2);}
              if(s1<=80)
              {   if(x>2100&&x<2470&&y<440){
                 if(jumpcount==-7&&y>390){
                 jumpcount=8;
                 jump=0;
                 block1=true;}
                 }
                 else if(block1==true&&jump==0&&y<440&&((y>290&&x<2140)||x>=2470))
                 {
                     jump=1;
                     Count=9;
                     jumpcount=-7;
                     block1=false;
                 }
                 if(x>=1590&&x<=2140&&y<=270){
                 if(jumpcount==0&&y>200){
                 jumpcount=8;
                 jump=0;
                 block2=true;
                 }}
                 else if(block2&&jump==0&&x<1590)
                 {
                     jump=1;
                     Count=9;
                     jumpcount=-2;
                     block2=false;
                 }
                   if(block2&&jump==0&&(x>2140&&x<2470))
                 {  jump=1;
                     Count=10;
                     jumpcount=-7.20;
                     block2=false;
                 }
                  if((Count==9&&int(jumpcount)==-9)||(Count==10&&int(jumpcount)==-10))
                    {
                        jumpcount=8;
                        Count=8;
                        jump=0;
                    }
                if(x>2100&&x<2470&&y>470)
                {  if(jumpcount==8)
                    {jumpcount=1;
                    Count=1;}
                }
                else if(Count==1&&jumpcount==1)
                {    jumpcount=8;
                    Count=8;
                }
                if(x<2140&&block1)
                {  if(jumpcount==8)
                    {jumpcount=6;
                    Count=6;}
                }
                else if(Count==6&&jumpcount==6)
                {    jumpcount=8;
                    Count=8;
                }
                  s.sprite(x-1100,y,walkcountL,walkcountR,left,right,standing);
               hs.health(x-1115,y,s1);}}
               else
              {for(size_t i=0;i<bulletvectors.size();i++){
              v.check(bulletvectors[i],villainx+600,d3);
              v1.check(bulletvectors[i],villainx+900,d4);}
              if(d3<=80)
                {v.sprite1(villainx+600,535,villainwcount,vleft,vright);
                 hv.health(villainx+600,535,d3);}
               if(d4<=80){
                 v1.sprite1(villainx+900,535,villainwcount,vleft,vright);
                 hv1.health(villainx+900,535,d4);}
                 if(s1<=80)
                 {s.sprite(x-2200,y,walkcountL,walkcountR,left,right,standing);
                 hs.health(x-2215,y,s1);}}
              }
class FONT
{ private:
    sf::Font font[2];
    sf::Text text[3];
    sf::Sprite BCK;
    sf::Texture bck;
  public:
       void FNT(int(d1))
      {  font[0].loadFromFile("CASTELAR.ttf");
        font[1].loadFromFile("BRLNSDB.ttf");
        text[0].setFont(font[0]);
        text[1].setFont(font[0]);
        text[2].setFont(font[1]);
        text[0].setCharacterSize(60.0f);
        text[0].setOutlineThickness(6.0f);
        text[1].setCharacterSize(60.0f);
        text[1].setOutlineThickness(6.0f);
        text[2].setOutlineThickness(2.0f);
        text[0].setString(" Your score is :");
        text[1].setString(std::to_string(d1));
        text[2].setString("BACK");
         text[0].setColor(sf::Color(150,200,150));
         text[1].setColor(sf::Color(80,100,80));
         text[2].setColor(sf::Color(80,100,80));
         text[0].setPosition(200,300);
         text[1].setPosition(780,300);
          text[2].setPosition(480,490);
         window.draw(text[0]);
         window.draw(text[1]);
          window.draw(text[2]);}
         sf::Sprite BACK()
         { bck.loadFromFile("back.png");
           BCK.setTexture(bck);
           BCK.setScale(0.10,0.08);
           BCK.setPosition(400,450);
             return BCK;
         }
};
int main(){
    int x=0,y=0,walkcountL=0,walkcountR=0,left=0,right=0,jump=0,neg=1,villainx=0,villainwcount=0;
    int velocity=5,vleft=0,vright=0,standing=1,press=0,bulletspeedX=10,bulletspeedY=10,countbg=0;
    bool block1=false,block2=false,mousepress=false,win=false,loss=false;
    float d1=0,d2=0,d3=0,d4=0,s1=0,jumpcount=8.0,Count=8.0,mousex=0.0,mousey=0.0;
    Sprite spritebg;
    sf::Sprite sprite=spritebg.anime();
     MENU m;
     sf::Sprite play=m.Play();
     sf::Sprite Exit =m.EXit();
    shootsound ss,sp;
    sf::Sound ss1=ss.Shootsound();
    sf::Sound sp1=sp.clicksound();
    SOUND mu;
    FONT B;
    sf::Sprite bck=B.BACK();
    while (window.isOpen())
    {
    sf::Event event;
        while(window.pollEvent(event)){
               if(event.type==sf::Event::Closed)
               {window.close();}}
               window.clear(sf::Color(200,200,200));
                mousex=sf::Mouse::getPosition().x;
                mousey=sf::Mouse::getPosition().y;
               if(!mousepress){
                   sf::View view;
                   view.reset(sf::FloatRect(0,0,1000,700));
                   window.setView(view);
                   window.draw(play);
                   window.draw(Exit);
                    window.draw(sprite);
                    m.TEXT();
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&(mousex>680&&mousex<760&&mousey>360&&mousey<440))
               {
                   mousepress=true;
                   sp1.play();
               }
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&(mousex>680&&mousex<760&&mousey>485&&mousey<565))
                       {
                           window.close();
                       }
               }
                else if(mousepress&&!win&&!loss) {
                background bg;
                 villain1 v,v1;
                 Sprite s;
                 healthscore hs,hv,hv1;
                 BulletV vbullet;
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                   {
                        sp1.play();
                   mousepress=false;}
                if(d1>=79&&d2>=79&&d3>=79&&d4>=79)
                {
                    win=true;
                }
                 if(s1>=79)
                {
                    loss=true;
                }
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {left=0;
                right=1;
                standing=0;
                x+=10;
                if(walkcountR==7)
                walkcountR=0;
                else
                walkcountR+=1;}
               else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&(x>0))
                {left=1;
                right=0;
                standing=0;
                x-=10;
                if(walkcountL==7)
                walkcountL=0;
                else
                walkcountL+=1;}
                if(!jump)
                {if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {jump=1;
                standing=0;}}
                else {
                if(jumpcount>=-Count){
                neg=1;
                 if (jumpcount<0){
                 neg=-1;}
                y-=(jumpcount*jumpcount)*neg;
                jumpcount-=1;}
                 else
                   {jump=0;
                   jumpcount=Count;
                   }}
    villainmotion( velocity, vleft,vright, villainwcount,villainx);
    bg=background(x,countbg);
    villainshoot( s,bulletspeedX,bulletspeedY,villainx,x,y,d1,d2,d3,d4,vright,vleft ,s1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
    press=1;
    ss1.play();}
    ladybulletposition(x,y,left,right,press);
    ladybulleterase(x,left ,right,s1,villainx);
    villainbullet_health_lady(v,v1,hv,hv1,hs,s ,x,y+535,s1,d1,d2 ,d3,d4,vleft,vright,villainx,left,right,walkcountL,walkcountR,standing,villainwcount,jump,jumpcount,Count,block1,block2);
    }
                 else if(win||loss)
                   {window.draw(bck);
                   B.FNT(d1+d2+d3+d4);
                   sf::View view;
                   view.reset(sf::FloatRect(0,0,1000,700));
                   window.setView(view);
                   if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&(mousex>600&&mousex<750&&mousey>500&&mousey<600))
                   {  sp1.play();
                       mousepress=false;win=false;loss=false;
                   d1=0.0;d2=0.0;d3=0.0;d4=0.0;s1=0;x=0;y=0;}
                 }
    window.display();}}








