#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/utsname.h>

#define SIZE (sizeof(people)/(2 * sizeof(char *)))

char *who = "who";

int main (int argc,char *argv[]) 
//main (int argc,char *argv[]) 
{
   FILE *fin, *foo, *popen();
   int  i;
   char buf[BUFSIZ],username[20],where[16],mon[4],day[3],time[6],from[30]; 

   char *people[][2] = {  { "zvondien", "Holi Zoli!     " },
                          { "tvoss",    "Tom Voss       " },
                          { "mcross",   "Matthew Cross  " },
                          { "pagano",   "Some Pagano guy  " },
                          { "berrey",   "Berrey guy       " },
                          { "masc0117", "[1m[5mCS560 B-Boy  [0m" },
                          { "khudson",  "Kelsey Hudson    " },
                          { "doreh",    "Issa Doreh       " },
                          { "aboaziza", "Amal Aboaziza    " },
                          { "baterina", "Eric Baterina    " },
                          { "shire",    "Brian Shire      " },
                          { "bhoang",   "Bobby Hoang      " },
                          { "sarkar",   "Mahasweta Sarkar!" },
                          { "hoang3",   "Tuan the SIM Man " },
                          { "deastman", "Derrick the Man " },
                          { "aluong",   "Anthony de Man  " },
                          { "cruzv",    "Victor the Man  " },
                          { "kklein",   "Kenneth/Scott K." },
                          { "ramos1",   "Jason-CS532     " },
                          { "windisch", "Dwayne-CS532    " },
                          { "dangc",    "Christopher-CS532" },
                          { "linh1",    "Linh Nguyen     " },
                          { "dlukas",   "Master's lil bro" },
                          { "tran33",   "Bruce Wannabe  " },
                          { "kzhu",     "Joyee the ircer" },
                          { "wenger",   "Tigerlilys Bro " },
                          { "prey",     "UCSD nerd-guy  " },
                          { "hai1",     "Mr. Ocean Xpert" },
                          { "sdsuvbc",  "Stephen da V-Ba" },
                          { "cheong",   "Isaac da Man   " },
                          { "amedrano", "Arch-Master M  " },
                          { "antonoff", "Joe the Man    " },
                          { "jhung",    "Jeffrey the Man" },
                          { "lee18",    "Jerry Lee      " },
                          { "tang2",    "Edgar Bautista " },
                          { "haddad",   "Fareed da Man  " },
                          { "symbol",   "Prof Drobnies  " },
                          { "argatide", "Paris the Man  " },
                          { "braulio",  "Wil the dude   " },
                          { "quang",    "Nghiep da Man  " },
                          { "mmoran",   "Marco the Man  " },
                          { "kellogg",  "C. Kevin       " },
                          { "pelletie", "Adam the C Man " },
                          { "paliguta", "Pal Plus !     " },
                          { "neff",     "Alex da Mathman " },
                          { "kinkel",   "Steve the Man  " },
                          { "gleonard", "Professor Guy  " },
                          { "roblesr",  "Rudy da Man    " },
                          { "sumabat",  "James the Man  " },
                          { "denune",   "John Denune-guy" },
                          { "rrevilla", "Rex-bo         " },
                          { "mpratt",   "Murray da Man  " },
                          { "lukas",    "Master's Master" },
                          { "academic", "Boss Lady !    " },
                          { "arceo",    "JJ the IRC-guy " },
                          { "nguyen83", "mail.sdsu spy  " },
                          { "mquinto",  "IRC casualty M " },
                          { "molon",    "Noel tha dude  " },
                          { "slinh",    "Shirley da CS  " },
                          { "harrill",  "Drew Harrill   " },
                          { "alday",    "The QUAKE guy  " },
                          { "ehoward",  "Ed-Dog         " },
                          { "handal",   "Philly Boy     " },
                          { "grapilon", "[1m[5mGraps Jr!      [0m" },
                          { "grapster", "[1m[5mGrapster Jr!      [0m" },
                          { "ebautist", "Mr. Riceman !  " },
			  { "preutz",   "Blue Berry     " },
                          { "swilensk", "Seth Blink     " },
                          { "stremler", "Stewart        " },
                          { "spydell",  "Andy           " },
                          { "tran4"  ,  "Thanh  =)      " },
                          { "hariz",    "Mr Joe Zone    " },
                          { "nash",     "Mr. SysAdmin   " },
                          { "jwolf"   , "SKA man        " },
                          { "gudlaugs", "HarlequinN     " },
                          { "stewart",  "Faculty Advisor" },
                          { "acm"     , "the SDSU chap  " },
                          { "mmarcus" , "WonderBoy!     " },
                          { "adanm",    "SGI dude       " },
                          { "vortiz",   "Muerto!!!!!    " },
                          { "vanzoest", "[1m[5mWeb Dude       [0m" },
                          { "parikh",  "[1m[5mHot Source     [0m" },
                          { "reutz",    "Cheese Cake    " },
                          { "ok",       "Mr.Bozo himself" },
                          { "achiw",    "Susie-q        " },
                          { "kamdar",   "Mr.Mafia       " },
                          { "killen",   " --| PUNK |--  " },
                          { "qclark",   "Apologize!     " },
                          { "bigstan",  "Pookie RuLeZ!  " },
                          { "natas",    "Satan is here! " },
                          { "treed",    "Linux dude!    " },
                          { "krueger",  "Repeats Classes" },
                          { "jclement", "The clement    " },
                          { "fischer",  "Linda          " },
                          { "horrick",  "Brad The Man   " },
                          { "mthomas",  "Fortran Lady   " },
			  { "alamillo", "ICEWOMAN       " },
			  { "pmoua",    "Pete the Dude  " },
			  { "mixermike", "M. Pangan...  " },
			  { "nobody",   "Nobody knows.. " },
                          { "root",  "[1m[5mroot user - WARNING [0m" },
			  { "www-data", "web tools      " },
			  { "dancalan", "Raymond-       " },
                          { "vbaker",   "wwmatrix.com =)" }};


   fin = popen(who,"r");

   if (argc==2)
   { 
      if (strcmp(argv[1],"-l")==0)
      {
         system("clear");
         printf("%60s\n", "List of Bozos to check for!") ;
         for (i=0;i<80;i++) putchar('-') ;
   	 printf("\n");

         for (i=0;i<SIZE;i++)
            printf( "      %-8s  %-15s\n",people[i][0],people[i][1]);
      }
      else
      {
         printf("Usage:  bozo\n") ;
         printf("        bozo -l\n\n") ;
         exit(1) ;
      }

   }
   else
   if (argc==1)
   {
      system("clear") ;
      struct utsname buffer;

      errno = 0;
      if (uname(&buffer) == -1) {
	      perror("uname") ;
	      exit(EXIT_FAILURE);
      }
//      printf("%s (%s)", buffer.nodename, buffer.sysname);

/*      #ifdef _GNU_SOURCE
      printf("domain name = %s\n", buffer.domainname);
      #endif
*/

//      printf("%52s\n", "Bozos currently on %s", buffer.sysname) ;
      printf("%52s\n", "Bozos currently on Rohan!\n", buffer.nodename, buffer.sysname);
      for(i=0;i<80;i++) putchar( '-') ;
      printf("\n");

      printf("%-8s\t%s\t\t%s \t\t%s%s%s\t%s\n",
      "LOGIN","NAME","TTY","DATE","_","TIME","FROM");
      for(i=0;i<80;i++) putchar( '-') ; printf("\n");

      while (fgets(buf,sizeof(buf),fin)!=NULL) 
      {
	 strcpy(from,"                  ");
         sscanf(buf,"%s %s %s %s %s %s",username,where,mon,day,time,from);

         for (i=0;i<SIZE;i++)
         {
            if (strcmp(people[i][0],username)==0) 
   	    {
               printf("%-8s -- %15s on %-7s since  %s %2s  %s  %s\n",
               username,people[i][1],where,mon,day,time,from);
            }
         }
      }
   }
   else
      {
         printf("Usage:  bozo\n") ;
         printf("        bozo -l\n\n") ;
         exit(1) ;
      }
 
printf("\n");
system("uptime");
   for (i=0;i<80;i++) putchar('_') ;

   printf("Ha Ha\n");
   pclose(fin) ;
   return EXIT_SUCCESS;
}

