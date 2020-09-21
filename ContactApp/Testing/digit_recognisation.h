
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream> 
#include <algorithm>

using namespace std;
long double inp_file[80000],temp[80000],ci[1000][12],ai[12],r[13],a[6][6],avg_a[6][6],b[6][33],avg_b[6][33],pi[6],avg_pi[6],alpha[1000][6],beta[1000][6],delta[1000][6],pstar,gamma[1000][6],gammaSum[6],zi[1000][6][6],prob;
long double sinW[]={1,2.552914,4,5.242640,6.196152,6.795554,7,6.795554,6.196152,5.242640,4,2.552914271,1};
long double hamW[320];
long double w[]={0.0,1.0, 3.0, 7.0, 13.0, 19.0, 22.0, 25.0, 33.0, 42.0, 50.0, 56.0, 61.0};
int scount,fcount[31],p=12,e,s,M=32,N=5,o[1000],psi[1000][6],qstar[1000];

void DCshift(){                                                 //this does the dc shift in the input data
	    long double dc=0;
        for(int i=0;i<scount;i++) dc+=inp_file[i];
        dc/=scount;
        for(int i=0;i<scount;i++) inp_file[i]-=dc;
}

void normalise(){                                                // normalising input data in inp_file[] array
        int i; long double max=inp_file[0];
        for( i=1;i<scount;i++) if(abs(inp_file[i])>max) max=abs(inp_file[i]);
        for(i=0;i<scount;i++){
		 inp_file[i]=(long double)(inp_file[i]*5000)/(long double)max; 
	}
}


void store(string s1){                         // this function stores the input data from file to array
	ifstream in1;
	in1.open(s1.c_str(),ios::in);
	long double x;
	scount=0;
	if(in1==NULL) cout<<"file not open\n";
	while(in1>>x){
		//cout<<x<<" ";
	    inp_file[scount]=x;
		scount++;
	}
	in1.close();
}

long double energy(int s){                                      //energy calculation for a frame starting from index s
	   long double sum=0;
	   for(int i=s;i<(s+320);i++) sum+=(inp_file[i]*inp_file[i]);
       return sum/(long double)320;
}

void trim(string fn,int u,int live){                      //trim function finds start and end marker and stores in s and e respectively
	int i;
	long double e1,e2;

	for(i=live;i<(live+320);i++)
		e1=energy(i);
	//cout<<e1<<" ";

	for(i=live+320;i<scount-640;){
	   // e1=energy(i);
		//if(ot==NULL) cout<<"not";
		//cout<<e1<<" ";
		//i+=320;
		e2=energy(i);
		i+=320;
		if(e2>=(long double)1000*e1){                     //s will store he starting index of the frame having the energy more than 
		   s=i;                                          //or equal to 10 times the energy of previous frame
		   break;
		} 
	}
	e=scount-320;                                      //initialising e

    for(i=scount-320;i>=0;i--)
		e1=energy(i);
	//cout<<e1<<" \n";

	for(i=scount-640;i>=0;){
	   // e1=energy(i);
		//cout<<e1<<" ";
		//i-=320;
		e2=energy(i);
		i-=320;
		if(e2>=(long double)1000*e1){
		   e=i+320;
		   break;
		} 
	}
	fcount[u]=(e-s+1-320)/80;       // fcount[u] has number of frames in the trimmed data of the utterance u
}

void hammingW(){                    //it calculates hamming window 
	for(int i=0;i<320;i++){
	    hamW[i]=0.54-(0.46*(cos((2*3.14159265*i)/319)));
	}
}

void Ri(int start){
	 double sum=0;
	 //long double temp[320];
	 int c1=0;

	 for(int j=start;j<(start+320);j++){         //applying hamming window
		    temp[j]=inp_file[j]*hamW[c1++];
	 }
	 
	 for(int i=0;i<=p;i++){
		sum=0;

		for(int j=start;j<(start+320);j++){
		if(j+i<(start+320)){
		  sum+=temp[j+i]*temp[j];
		}
		}
		r[i]=sum;       
	 }
	
}

void Ai(){
    double sum=0;
    int i,j;
    double e[13];
	double a[13][13];
	e[0]=r[0];
    for(i=1;i<=p;i++){
  	    sum=0;
		for(j=1;j<i;j++)  sum+=a[j][i-1]*r[i-j];
		if(i==1) sum=0;
		a[i][i]=(r[i]-sum)/e[i-1];
        
		for(j=1;j<i;j++) a[j][i]=a[j][i-1]-a[i][i]*a[i-j][i-1];
    	e[i]=(1-a[i][i]*a[i][i])*e[i-1];
    }
  
    for(i=1;i<=p;i++){
        ai[i]=a[i][p];
    }
  }
 
void Ci(int index){
	double sum=0;
	for(int m=1;m<=p;m++){
		sum=0;
		if(m>1) for(int k=1;k<m;k++) sum+=(long double)(k*ci[index][k]*ai[m-k])/(long double)m;
		ci[index][m]=ai[m]+sum;
	}
	for(int i=1;i<=p;i++){
	   ci[index][i]*=sinW[i]; //applying raised sine window to cepstral coefficients
	}
	
}

void ceps_coef(string fn,int u){                //this is for finding cepstral coefficients 
	int i,start=s,index=1;                      //variable index specifies the frame number
	ifstream inFile;
	inFile.open(fn.c_str(),ios::in);
	if(inFile!=NULL){
    for(i=1;i<=fcount[u];i++){
		 Ri(start);
		 start+=80;                                  // Due to overlapping next frame starts from 320-240=80 index
		 Ai();
		 Ci(index++);
		}
	}
}

long double tokhura(int l,ifstream &inFile){         //to calculate tokhura distance
	long double sum=0,x;
	for(int k=1;k<=12;k++){
	   inFile>>x;
	   sum+=w[k]*(ci[l][k]-x)*(ci[l][k]-x);
	}
	return sum;
}

void obs_seq(string fn,int u){                       //it calculates observation sequence of the corresponding input file
	int i,j,loc=-1;
	
	long double min=INT_MAX;
	ifstream inFile;
	//ofstream ot;
	//ot.open(s.c_str(),ios::out);
	//if(ot==NULL) cout<<"obs_se not open\n";
	
	for(i=1;i<=fcount[u];i++){                      //it picks a frame and compare its cepstral coefficients with all the rows of the given codebook
		inFile.open("Codebook\\codebook.txt",ios::in);
		min=INT_MAX;
		loc=-1;
		for(j=1;j<=M;j++){
			if(tokhura(i,inFile)<min){
			   min=tokhura(i,inFile);
			   loc=j;                                //loc sstores the index for which tokhura distance is minimum
			}
		}
        //ot<<loc<<"   ";
		o[i]=loc;
		inFile.close();
	}
	
	//ot.close();
}

void prob1(int c,string fn,int u){                                          //solution to problem 1
    int i,j,t;
	long double x;

    for(i=1;i<=N;i++){                                 //initialization for alpha matrix
	    alpha[1][i]=(pi[i])*(b[i][o[1]]);
		//cout<<alpha[1][i]<<"  ";
	}
	//cout<<endl;
	for(t=1;t<fcount[u];t++){                                   //induction for alpha matrix
	    for(j=1;j<=N;j++){
			x=0;
			for(i=1;i<=N;i++)
				x+=(alpha[t][i])*(a[i][j]);

			alpha[t+1][j]=x*(b[j][o[t+1]]);
			//cout<<alpha[1][i]<<"  ";
		}
		//cout<<endl;
	}

    for(i=1;i<=N;i++){                                 //initialization for beta matrix
	    beta[fcount[u]][i]=1;
	}

	for(t=fcount[u]-1;t>=1;t--){                               //induction for beta matrix
		for(i=1;i<=N;i++){
		   x=0;
		   for(j=1;j<=N;j++)
			   x+=a[i][j]*b[j][o[t+1]]*beta[t+1][j];

		   beta[t][i]=x;
		}
	}
    prob=0;
	for(i=1;i<=N;i++)
		prob+=alpha[fcount[u]][i];                               //prob is the probability of observation,o given lambda
	
}




void read(string fn,string s6,bool first,int u){                                                  //reads from files and stores in array
	int i,j;
	long double x;
	string s="obs_seq_",s1;
	s.append(fn);
	ifstream in1,in2,in3,in4;

	if(first==true)                                        //if first is true then model to be considered is the given initial model
	    in1.open("a.txt");
	else{
	    s1="Model\\avg_";                                         //otherwise considering the average model
		s1.append(s6);
		s1.append("_a.txt");
		//cout<<"This";
		in1.open(s1.c_str());
	}

    for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			in1>>x;
			a[i][j]=x;
		}
	}
    
    if(first==true)
	    in2.open("b.txt");
	else{
	    s1="Model\\avg_";
		s1.append(s6);
		s1.append("_b.txt");
		in2.open(s1.c_str());
	}
	for(i=1;i<=N;i++){
		for(j=1;j<=M;j++){
			in2>>x;
			b[i][j]=x;
		}
	}
    
	for(i=1;i<=N;i++){
		pi[i]=0;
	}

	pi[1]=1;
	
	in1.close();
	in2.close();
	
}


int hmm()
{   
    int i,j,k,digit;
	bool first=true;
	string s1,s2,s3,s4,s5,s6,s7;
	ofstream ot;
	stringstream ss;
	s3=".txt";
	char option;
	long double max;
	hammingW();                                     
	

	 first=false;
		       
		       ifstream in1;

		       system("Recording_Module.exe 3 input_file.wav input_file.txt");  //live recording
			   in1.open("input_file.txt",ios::in);
			   s1="input_file.txt";

			   store(s1);
			   trim(s1,0,16000);
			   DCshift(); 
	           normalise();
			   ceps_coef(s1,0);
			   obs_seq(s1,0);
			   max=INT_MIN;
			   digit=-1;
			   for(i=1;i<=16;i++){
				   if(i==14) continue;
				   if(i==5) continue;
				   if(i==3||i==6||i==7)continue;
				   if(i==12) continue;
				   ss<<i;
				   ss>>s6;
				   s5=s6;
				   s6="a_";
				   s6.append(s5);
				   cout<<s6<<" "<<s1<<endl;
				   ss.clear();
				   //ot.open("Fin_mo_input_file.txt",ios::out|ios::trunc);
				   //ot.close();
			        read(s1,s6,first,0);
					prob1(1,s1,0);
					if(prob>max){
					      max=prob;
						  digit=i;
					 }
			   }
			   in1.close();
	return digit;
}
int hmm2()
{   
    int i,j,k,digit;
	bool first=true;
	string s1,s2,s3,s4,s5,s6,s7;
	ofstream ot;
	stringstream ss;
	s3=".txt";
	char option;
	long double max;
	hammingW();                                     
	

	 first=false;
		       
		       ifstream in1;

		       system("Recording_Module.exe 3 input_file.wav input_file.txt");  //live recording
			   in1.open("input_file.txt",ios::in);
			   s1="input_file.txt";

			   store(s1);
			   trim(s1,0,16000);
			   DCshift(); 
	           normalise();
			   ceps_coef(s1,0);
			   obs_seq(s1,0);
			   max=INT_MIN;
			   digit=-1;
			   for(i=17;i<=19;i++){
				   ss<<i;
				   ss>>s6;
				   s5=s6;
				   s6="a_";
				   s6.append(s5);
				   cout<<s6<<" "<<s1<<endl;
				   ss.clear();
				   //ot.open("Fin_mo_input_file.txt",ios::out|ios::trunc);
				   //ot.close();
			        read(s1,s6,first,0);
					prob1(1,s1,0);
					if(prob>max){
					      max=prob;
						  digit=i;
					 }
			   }
			   in1.close();
	return digit;
}
