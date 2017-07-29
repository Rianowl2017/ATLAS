void Higgsanalysis()
{
//Open the root files
TFile *si =TFile::Open("/home/rian/Downloads/root-6.08.06/bin/mc_160155.ggH125_ZZ4lep.root"); //si ->Signal , ba->background 
TFile *ba =TFile::Open("/home/rian/Downloads/root-6.08.06/bin/mc_105986.ZZ.root");      
TTree *mini_si = (TTree*)si->Get("mini");
TTree *mini_ba = (TTree*)ba->Get("mini");
//Declare variables 
UInt_t n_si;UInt_t n_ba;
UInt_t type_si[6];UInt_t type_ba[6];
float charge_si[6];float charge_ba[6];
float E_si[6],pt_si[6],eta_si[6],phi_si[6];float E_ba[6],pt_ba[6],eta_ba[6],phi_ba[6];
mini_si->SetBranchAddress("lep_n",&n_si);
mini_si->SetBranchAddress("lep_type",&type_si);
mini_si->SetBranchAddress("lep_charge",&charge_si);
mini_si->SetBranchAddress("lep_E",&E_si);
mini_si->SetBranchAddress("lep_pt",&pt_si);
mini_si->SetBranchAddress("lep_eta",&eta_si);
mini_si->SetBranchAddress("lep_phi",&phi_si);
mini_ba->SetBranchAddress("lep_n",&n_ba);
mini_ba->SetBranchAddress("lep_type",&type_ba);
mini_ba->SetBranchAddress("lep_charge",&charge_ba);
mini_ba->SetBranchAddress("lep_E",&E_ba);
mini_ba->SetBranchAddress("lep_pt",&pt_ba);
mini_ba->SetBranchAddress("lep_eta",&eta_ba);
mini_ba->SetBranchAddress("lep_phi",&phi_ba);
//The actual invariant mass of the Z Boson   
float zmass=91.1876;
//Counting variables 
int n_1_si=0;int n_2_si=0;int n_3_si=0;
int n_4_si=0;int n_2pairleps_si=0;int n_dileps_si=0;
int n_5_si=0;int n_6_si=0;	
int n_1_ba=0;int n_2_ba=0;int n_3_ba=0;
int n_4_ba=0;int n_2pairleps_ba=0;int n_dileps_ba=0;
int n_5_ba=0;int n_6_ba=0;
float mass_1_si;float mass_2_si;
float mass_1_ba;float mass_2_ba;
TLorentzVector a;TLorentzVector b;TLorentzVector c;TLorentzVector d;

ofstream file1,file2,file4;
//file1.open ("One lepton mass.txt");
//file2.open ("Else.txt");
//file4.open ("Four Number.txt");

//Creating histograms
THStack *hs = new THStack("hs","Invariant Mass of the Higgs Boson (Signal+Background) 13TeV "); 
THStack *hs2 = new THStack("hs2","Invariant Mass of the Higgs Boson (Signal+Background) 8TeV "); 
TH1F *h1 = new TH1F("h1","Invariant Mass of the Higgs Boson(Signal) 13TeV",100,0,700); 
TH1F *h2 = new TH1F("h2","Invariant Mass of the Higgs Boson(Background) 13TeV",100,0,700);
TH1F *h3 = new TH1F("h3","Invariant Mass of the Higgs Boson(Signal) 8TeV",100,0,700); 
TH1F *h4 = new TH1F("h4","Invariant Mass of the Higgs Boson(Background) 8TeV",100,0,700);
TH2F *h2d = new TH2F("h2d","ZZ* Boson Mass",100,50,130,100,50,130);
//Signal (4leps)   		
 for (int i=0;i<mini_si->GetEntries();i++) 
 {
 mini_si->GetEntry(i);
  switch(n_si)
  {
  case 1: n_1_si++;break;
  case 2: n_2_si++;break;
  case 3: n_3_si++;break;
  case 4: 
  {
  n_4_si++;
     if(type_si[0]==13&&type_si[1]==13&&type_si[2]==11&&type_si[3]==11&&charge_si[0]!=charge_si[1]&&charge_si[2]!=charge_si[3]) 
     {
     n_2pairleps_si++;
     a.SetPtEtaPhiE(pt_si[0],eta_si[0],phi_si[0],E_si[0]);
     b.SetPtEtaPhiE(pt_si[1],eta_si[1],phi_si[1],E_si[1]);
     c.SetPtEtaPhiE(pt_si[2],eta_si[2],phi_si[2],E_si[2]);
     d.SetPtEtaPhiE(pt_si[3],eta_si[3],phi_si[3],E_si[3]);
     mass_2_si=(a+b).Mag()/1000;
     mass_1_si=(c+d).Mag()/1000;
       if((mass_1_si>(zmass-15)&&mass_1_si<(zmass+15))||(mass_2_si>(zmass-15)&&mass_2_si<(zmass+15))) 
       {n_dileps_si++;h1->Fill((a+b+c+d).Mag()/1000);h3->Fill((a+b+c+d).Mag()/1000);file1 <<"i= "<<i<<" "<<mass_1_si<<" "<<mass_2_si<<endl;}
       else file2 <<"i= "<<i<<" "<<mass_1_si<<" "<<mass_2_si<<endl;
     }
     if(type_si[0]==13&&type_si[1]==11&&type_si[2]==13&&type_si[3]==11&&charge_si[0]!=charge_si[2]&&charge_si[1]!=charge_si[3]) 
     {
     n_2pairleps_si++;
     a.SetPtEtaPhiE(pt_si[0],eta_si[0],phi_si[0],E_si[0]);
     b.SetPtEtaPhiE(pt_si[1],eta_si[1],phi_si[1],E_si[1]);
     c.SetPtEtaPhiE(pt_si[2],eta_si[2],phi_si[2],E_si[2]);
     d.SetPtEtaPhiE(pt_si[3],eta_si[3],phi_si[3],E_si[3]);
     mass_2_si=(a+c).Mag()/1000;
     mass_1_si=(b+d).Mag()/1000;
       if((mass_1_si>(zmass-15)&&mass_1_si<(zmass+15))||(mass_2_si>(zmass-15)&&mass_2_si<(zmass+15))) 
       {n_dileps_si++;h1->Fill((a+b+c+d).Mag()/1000);h3->Fill((a+b+c+d).Mag()/1000);file1 <<"i= "<<i<<" "<<mass_1_si<<" "<<mass_2_si<<endl;}
       else file2 <<"i= "<<i<<" "<<mass_1_si<<" "<<mass_2_si<<endl;
     }
     if(type_si[0]==13&&type_si[1]==11&&type_si[2]==11&&type_si[3]==13&&charge_si[0]!=charge_si[3]&&charge_si[1]!=charge_si[2]) 
     {
     n_2pairleps_si++;
     a.SetPtEtaPhiE(pt_si[0],eta_si[0],phi_si[0],E_si[0]);
     b.SetPtEtaPhiE(pt_si[1],eta_si[1],phi_si[1],E_si[1]);
     c.SetPtEtaPhiE(pt_si[2],eta_si[2],phi_si[2],E_si[2]);
     d.SetPtEtaPhiE(pt_si[3],eta_si[3],phi_si[3],E_si[3]);
     mass_1_si=(b+c).Mag()/1000;
     mass_2_si=(a+d).Mag()/1000;
       if((mass_1_si>(zmass-15)&&mass_1_si<(zmass+15))||(mass_2_si>(zmass-15)&&mass_2_si<(zmass+15))) 
       {n_dileps_si++;h1->Fill((a+b+c+d).Mag()/1000);h3->Fill((a+b+c+d).Mag()/1000);file1 <<"i= "<<i<<" "<<mass_1_si<<" "<<mass_2_si<<endl;}
       else file2 <<"i= "<<i<<" "<<mass_1_si<<" "<<mass_2_si<<endl;
     }
     if(type_si[0]==11&&type_si[1]==13&&type_si[2]==13&&type_si[3]==11&&charge_si[0]!=charge_si[3]&&charge_si[1]!=charge_si[2]) 
     {
     n_2pairleps_si++;
     a.SetPtEtaPhiE(pt_si[0],eta_si[0],phi_si[0],E_si[0]);
     b.SetPtEtaPhiE(pt_si[1],eta_si[1],phi_si[1],E_si[1]);
     c.SetPtEtaPhiE(pt_si[2],eta_si[2],phi_si[2],E_si[2]);
     d.SetPtEtaPhiE(pt_si[3],eta_si[3],phi_si[3],E_si[3]);
     mass_1_si=(a+d).Mag()/1000;
     mass_2_si=(b+c).Mag()/1000;
       if((mass_1_si>(zmass-15)&&mass_1_si<(zmass+15))||(mass_2_si>(zmass-15)&&mass_2_si<(zmass+15))) 
       {n_dileps_si++;h1->Fill((a+b+c+d).Mag()/1000);h3->Fill((a+b+c+d).Mag()/1000);file1 <<"i= "<<i<<" "<<mass_1_si<<" "<<mass_2_si<<endl;}
       else file2 <<"i= "<<i<<" "<<mass_1_si<<" "<<mass_2_si<<endl;
     }
     if(type_si[0]==11&&type_si[1]==13&&type_si[2]==11&&type_si[3]==13&&charge_si[0]!=charge_si[2]&&charge_si[1]!=charge_si[3]) 
     {
     n_2pairleps_si++;
     a.SetPtEtaPhiE(pt_si[0],eta_si[0],phi_si[0],E_si[0]);
     b.SetPtEtaPhiE(pt_si[1],eta_si[1],phi_si[1],E_si[1]);
     c.SetPtEtaPhiE(pt_si[2],eta_si[2],phi_si[2],E_si[2]);
     d.SetPtEtaPhiE(pt_si[3],eta_si[3],phi_si[3],E_si[3]);
     mass_1_si=(a+c).Mag()/1000;
     mass_2_si=(b+d).Mag()/1000;
       if((mass_1_si>(zmass-15)&&mass_1_si<(zmass+15))||(mass_2_si>(zmass-15)&&mass_2_si<(zmass+15))) 
       {n_dileps_si++;h1->Fill((a+b+c+d).Mag()/1000);h3->Fill((a+b+c+d).Mag()/1000);file1 <<"i= "<<i<<" "<<mass_1_si<<" "<<mass_2_si<<endl;}
       else file2 <<"i= "<<i<<" "<<mass_1_si<<" "<<mass_2_si<<endl;
     }
     if(type_si[0]==11&&type_si[1]==11&&type_si[2]==13&&type_si[3]==13&&charge_si[0]!=charge_si[1]&&charge_si[2]!=charge_si[3]) 
     {
     n_2pairleps_si++;
     a.SetPtEtaPhiE(pt_si[0],eta_si[0],phi_si[0],E_si[0]);
     b.SetPtEtaPhiE(pt_si[1],eta_si[1],phi_si[1],E_si[1]);
     c.SetPtEtaPhiE(pt_si[2],eta_si[2],phi_si[2],E_si[2]);
     d.SetPtEtaPhiE(pt_si[3],eta_si[3],phi_si[3],E_si[3]);
     mass_1_si=(a+b).Mag()/1000;
     mass_2_si=(c+d).Mag()/1000;
       if((mass_1_si>(zmass-15)&&mass_1_si<(zmass+15))||(mass_2_si>(zmass-15)&&mass_2_si<(zmass+15))) 
       {n_dileps_si++;h1->Fill((a+b+c+d).Mag()/1000);h3->Fill((a+b+c+d).Mag()/1000);file1 <<"i= "<<i<<" "<<mass_1_si<<" "<<mass_2_si<<endl;}
       else file2 <<"i= "<<i<<" "<<mass_1_si<<" "<<mass_2_si<<endl;
     }
     if(type_si[0]==11&&type_si[1]==11&&type_si[2]==11&&type_si[3]==11) 
     {
     n_2pairleps_si++;
     a.SetPtEtaPhiE(pt_si[0],eta_si[0],phi_si[0],E_si[0]);
     b.SetPtEtaPhiE(pt_si[1],eta_si[1],phi_si[1],E_si[1]);
     c.SetPtEtaPhiE(pt_si[2],eta_si[2],phi_si[2],E_si[2]);
     d.SetPtEtaPhiE(pt_si[3],eta_si[3],phi_si[3],E_si[3]);
     mass_1_si=(a+b).Mag()/1000;
     mass_2_si=(c+d).Mag()/1000;
       if((mass_1_si>(zmass-15)&&mass_1_si<(zmass+15))||(mass_2_si>(zmass-15)&&mass_2_si<(zmass+15))) 
       {n_dileps_si++;h1->Fill((a+b+c+d).Mag()/1000);h3->Fill((a+b+c+d).Mag()/1000);file1 <<"i= "<<i<<" "<<mass_1_si<<" "<<mass_2_si<<endl;}
       else file2 <<"i= "<<i<<" "<<mass_1_si<<" "<<mass_2_si<<endl;
     }	
     if(type_si[0]==13&&type_si[1]==13&&type_si[2]==13&&type_si[3]==13) 
     {
     n_2pairleps_si++;
     a.SetPtEtaPhiE(pt_si[0],eta_si[0],phi_si[0],E_si[0]);
     b.SetPtEtaPhiE(pt_si[1],eta_si[1],phi_si[1],E_si[1]);
     c.SetPtEtaPhiE(pt_si[2],eta_si[2],phi_si[2],E_si[2]);
     d.SetPtEtaPhiE(pt_si[3],eta_si[3],phi_si[3],E_si[3]);
     mass_1_si=(a+b).Mag()/1000;
     mass_2_si=(c+d).Mag()/1000;
       if((mass_1_si>(zmass-15)&&mass_1_si<(zmass+15))||(mass_2_si>(zmass-15)&&mass_2_si<(zmass+15))) 
       {n_dileps_si++;h1->Fill((a+b+c+d).Mag()/1000);h3->Fill((a+b+c+d).Mag()/1000);file1 <<"i= "<<i<<" "<<mass_1_si<<" "<<mass_2_si<<endl;}
       else file2 <<"i= "<<i<<" "<<mass_1_si<<" "<<mass_2_si<<endl;
     }	
  break;
  }
  case 5: n_5_si++;break;
  case 6: n_6_si++;break;
  default: break;
  }
 
 }

//Background(diZZ*)
for (int i=0;i<mini_ba->GetEntries();i++) 
 {
 mini_ba->GetEntry(i);
  switch(n_ba)
  {
  case 1: n_1_ba++;break;
  case 2: n_2_ba++;break;
  case 3: n_3_ba++;break;
  case 4: 
  {
  n_4_ba++;
    if(type_ba[0]==13&&type_ba[1]==13&&type_ba[2]==11&&type_ba[3]==11&&charge_ba[0]!=charge_ba[1]&&charge_ba[2]!=charge_ba[3]) 
    {
    n_2pairleps_ba++;
    a.SetPtEtaPhiE(pt_ba[0],eta_ba[0],phi_ba[0],E_ba[0]);
    b.SetPtEtaPhiE(pt_ba[1],eta_ba[1],phi_ba[1],E_ba[1]);
    c.SetPtEtaPhiE(pt_ba[2],eta_ba[2],phi_ba[2],E_ba[2]);
    d.SetPtEtaPhiE(pt_ba[3],eta_ba[3],phi_ba[3],E_ba[3]);
    mass_2_ba=(a+b).Mag()/1000;
    mass_1_ba=(c+d).Mag()/1000;
      if((mass_1_ba>(zmass-15)&&mass_1_ba<(zmass+15))||(mass_2_ba>(zmass-15)&&mass_2_ba<(zmass+15))) 
      {
      n_dileps_ba++;h2->Fill((a+b+c+d).Mag()/1000);h4->Fill((a+b+c+d).Mag()/1000);
      if(mass_1_ba>mass_2_ba) h2d->Fill(mass_1_ba,mass_2_ba);
      else h2d->Fill(mass_2_ba,mass_1_ba);
      }
    }	
    if(type_ba[0]==13&&type_ba[1]==11&&type_ba[2]==13&&type_ba[3]==11&&charge_ba[0]!=charge_ba[2]&&charge_ba[1]!=charge_ba[3]) 
    {
    n_2pairleps_ba++;
    a.SetPtEtaPhiE(pt_ba[0],eta_ba[0],phi_ba[0],E_ba[0]);
    b.SetPtEtaPhiE(pt_ba[1],eta_ba[1],phi_ba[1],E_ba[1]);
    c.SetPtEtaPhiE(pt_ba[2],eta_ba[2],phi_ba[2],E_ba[2]);
    d.SetPtEtaPhiE(pt_ba[3],eta_ba[3],phi_ba[3],E_ba[3]);
    mass_2_ba=(a+c).Mag()/1000;
    mass_1_ba=(b+d).Mag()/1000;
      if((mass_1_ba>(zmass-15)&&mass_1_ba<(zmass+15))||(mass_2_ba>(zmass-15)&&mass_2_ba<(zmass+15))) 
      {
      n_dileps_ba++;h2->Fill((a+b+c+d).Mag()/1000);h4->Fill((a+b+c+d).Mag()/1000);
      if(mass_1_ba>mass_2_ba) h2d->Fill(mass_1_ba,mass_2_ba);
      else h2d->Fill(mass_2_ba,mass_1_ba);
      }
    }	
    if(type_ba[0]==13&&type_ba[1]==11&&type_ba[2]==11&&type_ba[3]==13&&charge_ba[0]!=charge_ba[3]&&charge_ba[1]!=charge_ba[2]) 
    {
    n_2pairleps_ba++;
    a.SetPtEtaPhiE(pt_ba[0],eta_ba[0],phi_ba[0],E_ba[0]);
    b.SetPtEtaPhiE(pt_ba[1],eta_ba[1],phi_ba[1],E_ba[1]);
    c.SetPtEtaPhiE(pt_ba[2],eta_ba[2],phi_ba[2],E_ba[2]);
    d.SetPtEtaPhiE(pt_ba[3],eta_ba[3],phi_ba[3],E_ba[3]);
    mass_2_ba=(a+d).Mag()/1000;
    mass_1_ba=(b+c).Mag()/1000;
      if((mass_1_ba>(zmass-15)&&mass_1_ba<(zmass+15))||(mass_2_ba>(zmass-15)&&mass_2_ba<(zmass+15))) 
      {
      n_dileps_ba++;h2->Fill((a+b+c+d).Mag()/1000);h4->Fill((a+b+c+d).Mag()/1000);
      if(mass_1_ba>mass_2_ba) h2d->Fill(mass_1_ba,mass_2_ba);
      else h2d->Fill(mass_2_ba,mass_1_ba);
      }
    }	
    if(type_ba[0]==11&&type_ba[1]==13&&type_ba[2]==13&&type_ba[3]==11&&charge_ba[0]!=charge_ba[3]&&charge_ba[1]!=charge_ba[2]) 
    {
    n_2pairleps_ba++;
    a.SetPtEtaPhiE(pt_ba[0],eta_ba[0],phi_ba[0],E_ba[0]);
    b.SetPtEtaPhiE(pt_ba[1],eta_ba[1],phi_ba[1],E_ba[1]);
    c.SetPtEtaPhiE(pt_ba[2],eta_ba[2],phi_ba[2],E_ba[2]);
    d.SetPtEtaPhiE(pt_ba[3],eta_ba[3],phi_ba[3],E_ba[3]);
    mass_1_ba=(a+d).Mag()/1000;
    mass_2_ba=(b+c).Mag()/1000;
      if((mass_1_ba>(zmass-15)&&mass_1_ba<(zmass+15))||(mass_2_ba>(zmass-15)&&mass_2_ba<(zmass+15))) 
      {
      n_dileps_ba++;h2->Fill((a+b+c+d).Mag()/1000);h4->Fill((a+b+c+d).Mag()/1000);
      if(mass_1_ba>mass_2_ba) h2d->Fill(mass_1_ba,mass_2_ba);
      else h2d->Fill(mass_2_ba,mass_1_ba);
      }
    }	
    if(type_ba[0]==11&&type_ba[1]==13&&type_ba[2]==11&&type_ba[3]==13&&charge_ba[0]!=charge_ba[2]&&charge_ba[1]!=charge_ba[3]) 
    {
    n_2pairleps_ba++;
    a.SetPtEtaPhiE(pt_ba[0],eta_ba[0],phi_ba[0],E_ba[0]);
    b.SetPtEtaPhiE(pt_ba[1],eta_ba[1],phi_ba[1],E_ba[1]);
    c.SetPtEtaPhiE(pt_ba[2],eta_ba[2],phi_ba[2],E_ba[2]);
    d.SetPtEtaPhiE(pt_ba[3],eta_ba[3],phi_ba[3],E_ba[3]);
    mass_1_ba=(a+c).Mag()/1000;
    mass_2_ba=(b+d).Mag()/1000;
      if((mass_1_ba>(zmass-15)&&mass_1_ba<(zmass+15))||(mass_2_ba>(zmass-15)&&mass_2_ba<(zmass+15))) 
      {
      n_dileps_ba++;h2->Fill((a+b+c+d).Mag()/1000);h4->Fill((a+b+c+d).Mag()/1000);
      if(mass_1_ba>mass_2_ba) h2d->Fill(mass_1_ba,mass_2_ba);
      else h2d->Fill(mass_2_ba,mass_1_ba);
      }
    }	
    if(type_ba[0]==11&&type_ba[1]==11&&type_ba[2]==13&&type_ba[3]==13&&charge_ba[0]!=charge_ba[1]&&charge_ba[2]!=charge_ba[3]) 
    {
    n_2pairleps_ba++;
    a.SetPtEtaPhiE(pt_ba[0],eta_ba[0],phi_ba[0],E_ba[0]);
    b.SetPtEtaPhiE(pt_ba[1],eta_ba[1],phi_ba[1],E_ba[1]);
    c.SetPtEtaPhiE(pt_ba[2],eta_ba[2],phi_ba[2],E_ba[2]);
    d.SetPtEtaPhiE(pt_ba[3],eta_ba[3],phi_ba[3],E_ba[3]);
    mass_1_ba=(a+b).Mag()/1000;
    mass_2_ba=(c+d).Mag()/1000;
      if((mass_1_ba>(zmass-15)&&mass_1_ba<(zmass+15))||(mass_2_ba>(zmass-15)&&mass_2_ba<(zmass+15))) 
      {
      n_dileps_ba++;h2->Fill((a+b+c+d).Mag()/1000);h4->Fill((a+b+c+d).Mag()/1000);
      if(mass_1_ba>mass_2_ba) h2d->Fill(mass_1_ba,mass_2_ba);
      else h2d->Fill(mass_2_ba,mass_1_ba);
      }
      }
    if(type_ba[0]==11&&type_ba[1]==11&&type_ba[2]==11&&type_ba[3]==11) 
    {
    n_2pairleps_ba++;
    a.SetPtEtaPhiE(pt_ba[0],eta_ba[0],phi_ba[0],E_ba[0]);
    b.SetPtEtaPhiE(pt_ba[1],eta_ba[1],phi_ba[1],E_ba[1]);
    c.SetPtEtaPhiE(pt_ba[2],eta_ba[2],phi_ba[2],E_ba[2]);
    d.SetPtEtaPhiE(pt_ba[3],eta_ba[3],phi_ba[3],E_ba[3]);
    mass_1_ba=(a+b).Mag()/1000;
    mass_2_ba=(c+d).Mag()/1000;
      if((mass_1_ba>(zmass-15)&&mass_1_ba<(zmass+15))||(mass_2_ba>(zmass-15)&&mass_2_ba<(zmass+15))) 
      {
      n_dileps_ba++;h2->Fill((a+b+c+d).Mag()/1000);h4->Fill((a+b+c+d).Mag()/1000);
      if(mass_1_ba>mass_2_ba) h2d->Fill(mass_1_ba,mass_2_ba);
      else h2d->Fill(mass_2_ba,mass_1_ba);
      }
      }	
    if(type_ba[0]==13&&type_ba[1]==13&&type_ba[2]==13&&type_ba[3]==13) 
    {
    n_2pairleps_ba++;
    a.SetPtEtaPhiE(pt_ba[0],eta_ba[0],phi_ba[0],E_ba[0]);
    b.SetPtEtaPhiE(pt_ba[1],eta_ba[1],phi_ba[1],E_ba[1]);
    c.SetPtEtaPhiE(pt_ba[2],eta_ba[2],phi_ba[2],E_ba[2]);
    d.SetPtEtaPhiE(pt_ba[3],eta_ba[3],phi_ba[3],E_ba[3]);
    mass_1_ba=(a+b).Mag()/1000;
    mass_2_ba=(c+d).Mag()/1000;
      if((mass_1_ba>(zmass-15)&&mass_1_ba<(zmass+15))||(mass_2_ba>(zmass-15)&&mass_2_ba<(zmass+15))) 
      {
      n_dileps_ba++;h2->Fill((a+b+c+d).Mag()/1000);h4->Fill((a+b+c+d).Mag()/1000);
      if(mass_1_ba>mass_2_ba) h2d->Fill(mass_1_ba,mass_2_ba);
      else h2d->Fill(mass_2_ba,mass_1_ba);
      }
      }		
    break;
    }
    
  case 5: n_5_ba++;break;
  case 6: n_6_ba++;break;
  default: break;
  }
 
 }

TCanvas *cs = new TCanvas("cs","cs",1000,1000,1000,1000);
cs->SetLeftMargin(1);
cs->SetBottomMargin(1);
cs->Divide(1,2);
//Input values for Normalization
cout<<"Cross  "<<"efficiency "<<"Luminosity "<<"  N "<<endl;
//Signal (13TeV)
float cross_section_si_13=61.5E+03;
float efficieny_si=0.15588;  
float total_intergrated_luminosity_si=1; 
float Br_ZZ=0.02619;//Branching Ratio (H->ZZ*) M=125.0GeV
float Br_ll=0.033658;//Branching Ratio (Z->l+l-)
float N_si_13=cross_section_si_13*efficieny_si*total_intergrated_luminosity_si*Br_ZZ*Br_ll*Br_ll;
cout<<cross_section_si_13/1000<<"pb "<<efficieny_si*100<<"% "<<total_intergrated_luminosity_si<<"fb^-1 "<<N_si_13<<endl;
double integral;
integral=h1->Integral();
h1->Scale(1/integral);
h1->Scale(N_si_13);
//Background (13TeV)
float cross_section_ba_13=17.2E+03; 
float efficieny_ba=9.864E-03;  
float total_intergrated_luminosity_ba=1; 
float N_ba_13=cross_section_ba_13*efficieny_ba*total_intergrated_luminosity_ba;
cout<<cross_section_ba_13/1000<<"pb "<<efficieny_ba*100<<"% "<<total_intergrated_luminosity_ba<<"fb^-1 "<<N_ba_13<<endl;
double integral2;
integral2=h2->Integral();
h2->Scale(1/integral2);
h2->Scale(N_ba_13);
h1->SetFillColor(kRed);
h1->SetMarkerStyle(21);
h1->SetMarkerColor(kRed);
gStyle->SetOptStat(111111111);
hs->Add(h1);
h2->SetFillColor(kBlue);
h2->SetMarkerStyle(22);
h2->SetMarkerColor(kBlue);
hs->Add(h2);

cs->cd(1); hs->Draw("L");
hs->GetXaxis()->SetTitle("M4l [GeV]");
hs->GetYaxis()->SetTitle("Entries/7GeV");
hs->GetXaxis()->SetTitleOffset(1.5);
auto legend = new TLegend(0.1,0.7,0.48,0.9);
legend->SetTextSize(0.05);
legend->AddEntry("h1","Signal (4leptons)","p");
legend->AddEntry("h2","Background (di Z Boson)","p");
legend->Draw();

//Signal 8TeV
float cross_section_si_8=33.3E+03;
float N_si_8=cross_section_si_8*efficieny_si*total_intergrated_luminosity_si*Br_ZZ*Br_ll*Br_ll;
cout<<cross_section_si_8/1000<<"pb "<<efficieny_si*100<<"% "<<total_intergrated_luminosity_si<<"fb^-1 "<<N_si_8<<endl;
integral3=h3->Integral();
h3->Scale(1/integral3);
h3->Scale(N_si_8);
//Background 8TeV
float cross_section_ba_8=7.3E+03;   
float N_ba_8=cross_section_ba_8*efficieny_ba*total_intergrated_luminosity_ba;
cout<<cross_section_ba_8/1000<<"pb "<<efficieny_ba*100<<"% "<<total_intergrated_luminosity_ba<<"fb^-1 "<<N_ba_8<<endl;
integral4=h4->Integral();
h4->Scale(1/integral4);
h4->Scale(N_ba_8);
h3->GetXaxis()->SetTitle("M4l [GeV]");
h3->GetYaxis()->SetTitle("Entries(Events)/7 GeV ");
h3->SetFillColor(kRed);
h3->SetMarkerStyle(21);
h3->SetMarkerColor(kRed);
gStyle->SetOptStat(111111111);
h4->GetXaxis()->SetTitle("M4l [GeV]");
h4->GetYaxis()->SetTitle("Entries(Events)/7 GeV ");
h4->SetFillColor(kBlue);
h4->SetMarkerStyle(22);
h4->SetMarkerColor(kBlue);
h3->SetFillColor(kRed);
gStyle->SetOptStat(111111111);
hs2->Add(h3);
h4->SetFillColor(kBlue);
hs2->Add(h4);
cs->cd(2);hs2->Draw("L");
hs2->GetXaxis()->SetTitle("M4l [GeV]");
hs2->GetYaxis()->SetTitle("Entries/7GeV");
hs2->GetXaxis()->SetTitleOffset(1.5);
file1.close();

auto legend3 = new TLegend(0.1,0.7,0.48,0.9);
legend3->SetTextSize(0.05);
legend3->AddEntry("h3","Signal (4leptons)","p");
legend3->AddEntry("h4","Background (di Z Boson)","p");
legend3->Draw();

}
