#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

void dump(){
	TFile *f = new TFile("AcceptanceTrinity_e_05_1_maxElevation_20.root") ;
	TCanvas *c = (TCanvas*)f->Get("cAcceptance") ;
	TGraph *g = (TGraph*)c->FindObject("") ;
	
	ofstream myFile;
	myFile.open("AcceptanceTrinity_e_05_1_maxElevation_20.txt") ;
	TH1F *Enu = new TH1F("Enu", "", 100, 6, 11) ;
	//cout << Enu->GetNbinsX () << endl;
	for(int i=1;i <= Enu->GetNbinsX();i++){
		double enerNu = pow(10, Enu->GetBinLowEdge(i)) ;
		myFile << Enu->GetBinLowEdge(i) << " " << g->Eval(enerNu) << "\n" ;
	}
	myFile.close();
}
