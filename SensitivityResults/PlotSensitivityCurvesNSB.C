void PlotSensitivityCurvesNSB()
{
   int distances[] = { 20, 50, 80, 130, 190 };
   float dNSB[] = { 1, 2, 10 };
   float dLowerFoV[] = { 0, 1, 3, 10,  88.6 };
   float image[] = { 0.1, 0.3, 0.5, 0.7, 0.9 };
   int colors[] = {kRed, kBlue, kGreen, kMagenta,kBlack, kYellow, kCyan};
   int linestyles[] = {1, 7, 9, 2, 4};
   int iDefNum = 0;  
  
   TGraph *gr[4];
   TGraph *g ;
   TGraph *gra ;
   TMultiGraph *mgr = new TMultiGraph();

  TLegend *leg = new TLegend(0.34,0.54,0.65,0.9,"NSB");
  leg->SetTextSize(0.0506329);

   for(int d=0;d<3;d++)
    {
      TString sFileName;
      sFileName.Form("/home/mayamember/Trinity/SensitivityResults/DifferentialSensitivityTrinity_original.root",dNSB[d]);
      TFile f(sFileName.Data());
      TCanvas *c1 = (TCanvas*)f.Get("cDiffSensitivity");
      gr[d] = (TGraph*)c1->FindObject("");
      //h[d]->SetStats(0);
      gr[d]->SetLineWidth(2);
      if(d==iDefNum)
        gr[d]->SetLineWidth(3);
      gr[d]->SetLineColor(colors[d]);
      gr[d]->SetLineStyle(linestyles[d]);
      gr[d]->SetTitle("");
      sFileName.Form("%0.0f #times nominal",dNSB[d]);
      leg->AddEntry(gr[d],sFileName.Data(),"l");
      mgr->Add(gr[d]);
      f.Close();
    }
   //for(int d=5;d>0;d--)

   TString zFileName ;
   TString yFileName ;
   zFileName.Form("/home/mayamember/Trinity/SensitivityResults/DifferentialSensitivityTrinity_1.root") ;
   TFile z(zFileName.Data()) ;
   TCanvas *c2 = (TCanvas*)z.Get("cDiffSensitivity") ;
   g = (TGraph*)c2->FindObject("") ;
   mgr->Add(g) ;
   z.Close();

   yFileName.Form("/home/mayamember/Trinity/SensitivityResults/DifferentialSensitivityTrinity_0.root") ;
   TFile y(yFileName.Data()) ;
   TCanvas *c3 = (TCanvas*)y.Get("cDiffSensitivity") ;
   gra = (TGraph*)c3->FindObject("") ;
   mgr->Add(gra) ;

   TCanvas *c = new TCanvas("c","Sensitivity",750,500);
      c->cd();
   c->SetLogy();
   c->SetLogx();
   gStyle->SetPalette(kRainBow);
   mgr->Draw("aPLC PMC");
   //mgr->Draw("aPL");
   mgr->GetYaxis()->SetTitle(gr[0]->GetYaxis()->GetTitle());
   mgr->GetXaxis()->SetTitle(gr[0]->GetXaxis()->GetTitle());
   mgr->GetXaxis()->SetTitleSize(0.045);
   mgr->GetYaxis()->SetTitleSize(0.045);
   mgr->GetYaxis()->SetLabelSize(0.045);
   mgr->GetXaxis()->SetLabelSize(0.045);
   mgr->GetYaxis()->SetTitleOffset(1.1);
   mgr->GetXaxis()->SetTitleOffset(1.2);
   mgr->SetMinimum(1e-9);
   mgr->SetMaximum(1e-6);
  leg->Draw();
}
