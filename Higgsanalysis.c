void Higgsanalysis4()
{
//Open the root files
TFile *si =TFile::Open("/home/rian/Downloads/root-6.08.06/bin/mc_160155.ggH125_ZZ4lep.root"); //si ->Signal , ba->background 
TFile *ba =TFile::Open("/home/rian/Downloads/root-6.08.06/bin/mc_105986.ZZ.root");      
TTree *mini_si = (TTree*)si->Get("mini"); //si->Signal
TTree *mini_ba = (TTree*)ba->Get("mini"); //ba->Background
//Declare variables 
UInt_t n_si;UInt_t n_ba; //no of leptons
UInt_t type_si[6];UInt_t type_ba[6]; //type of leptoon 11->electon/positions 13->muon/antimuon
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
TLorentzVector a;TLorentzVector b;TLorentzVector c;TLorentzVector d;

int n_4leps_si=0; //For counting how many 4leps events in the mc sample
int n_4leps_ba=0;

TH1F *h1 = new TH1F("h1","Invariant Mass of the Higgs Boson ",220,80,300); 
TH1F *h2 = new TH1F("h2","Invariant Mass of the Higgs Boson(Background) ",220,80,300);
//Signal (gg->H-ZZ*->4l)
for (int i=0;i<mini_si->GetEntries();i++) 
 {
 mini_si->GetEntry(i);
 if(n_si==4&&charge_si[0]+charge_si[1]+charge_si[2]+charge_si[3]==0)
  {
  if(type_si[0]==11&&type_si[1]==11&&type_si[2]==11&&type_si[3]==11)
   { 
   n_4leps_si++;
   a.SetPtEtaPhiE(pt_si[0],eta_si[0],phi_si[0],E_si[0]);
   b.SetPtEtaPhiE(pt_si[1],eta_si[1],phi_si[1],E_si[1]);
   c.SetPtEtaPhiE(pt_si[2],eta_si[2],phi_si[2],E_si[2]);
   d.SetPtEtaPhiE(pt_si[3],eta_si[3],phi_si[3],E_si[3]);
   h1->Fill((a+b+c+d).Mag()/1000);
   }
  if(type_si[0]==13&&type_si[1]==13&&type_si[2]==13&&type_si[3]==13)
   { 
   n_4leps_si++;
   a.SetPtEtaPhiE(pt_si[0],eta_si[0],phi_si[0],E_si[0]);
   b.SetPtEtaPhiE(pt_si[1],eta_si[1],phi_si[1],E_si[1]);
   c.SetPtEtaPhiE(pt_si[2],eta_si[2],phi_si[2],E_si[2]);
   d.SetPtEtaPhiE(pt_si[3],eta_si[3],phi_si[3],E_si[3]);
   h1->Fill((a+b+c+d).Mag()/1000);
   }
  if(type_si[0]==11&&type_si[1]==11&&type_si[2]==13&&type_si[3]==13&&charge_si[0]!=charge_si[1]&&charge_si[2]!=charge_si[3]) 
   { 
   n_4leps_si++;
   a.SetPtEtaPhiE(pt_si[0],eta_si[0],phi_si[0],E_si[0]);
   b.SetPtEtaPhiE(pt_si[1],eta_si[1],phi_si[1],E_si[1]);
   c.SetPtEtaPhiE(pt_si[2],eta_si[2],phi_si[2],E_si[2]);
   d.SetPtEtaPhiE(pt_si[3],eta_si[3],phi_si[3],E_si[3]);
   h1->Fill((a+b+c+d).Mag()/1000);
   }
  if(type_si[0]==11&&type_si[1]==13&&type_si[2]==11&&type_si[3]==13&&charge_si[0]!=charge_si[1]&&charge_si[2]!=charge_si[3]) 
   { 
   n_4leps_si++;
   a.SetPtEtaPhiE(pt_si[0],eta_si[0],phi_si[0],E_si[0]);
   b.SetPtEtaPhiE(pt_si[1],eta_si[1],phi_si[1],E_si[1]);
   c.SetPtEtaPhiE(pt_si[2],eta_si[2],phi_si[2],E_si[2]);
   d.SetPtEtaPhiE(pt_si[3],eta_si[3],phi_si[3],E_si[3]);
   h1->Fill((a+b+c+d).Mag()/1000);
   }
  if(type_si[0]==11&&type_si[1]==13&&type_si[2]==13&&type_si[3]==11&&charge_si[0]!=charge_si[1]&&charge_si[2]!=charge_si[3]) 
   { 
   n_4leps_si++;
   a.SetPtEtaPhiE(pt_si[0],eta_si[0],phi_si[0],E_si[0]);
   b.SetPtEtaPhiE(pt_si[1],eta_si[1],phi_si[1],E_si[1]);
   c.SetPtEtaPhiE(pt_si[2],eta_si[2],phi_si[2],E_si[2]);
   d.SetPtEtaPhiE(pt_si[3],eta_si[3],phi_si[3],E_si[3]);
   h1->Fill((a+b+c+d).Mag()/1000);
   }
  if(type_si[0]==13&&type_si[1]==11&&type_si[2]==11&&type_si[3]==13&&charge_si[0]!=charge_si[1]&&charge_si[2]!=charge_si[3]) 
   { 
   n_4leps_si++;
   a.SetPtEtaPhiE(pt_si[0],eta_si[0],phi_si[0],E_si[0]);
   b.SetPtEtaPhiE(pt_si[1],eta_si[1],phi_si[1],E_si[1]);
   c.SetPtEtaPhiE(pt_si[2],eta_si[2],phi_si[2],E_si[2]);
   d.SetPtEtaPhiE(pt_si[3],eta_si[3],phi_si[3],E_si[3]);
   h1->Fill((a+b+c+d).Mag()/1000);
   }
  if(type_si[0]==13&&type_si[1]==11&&type_si[2]==13&&type_si[3]==11&&charge_si[0]!=charge_si[1]&&charge_si[2]!=charge_si[3]) 
   { 
   n_4leps_si++;
   a.SetPtEtaPhiE(pt_si[0],eta_si[0],phi_si[0],E_si[0]);
   b.SetPtEtaPhiE(pt_si[1],eta_si[1],phi_si[1],E_si[1]);
   c.SetPtEtaPhiE(pt_si[2],eta_si[2],phi_si[2],E_si[2]);
   d.SetPtEtaPhiE(pt_si[3],eta_si[3],phi_si[3],E_si[3]);
   h1->Fill((a+b+c+d).Mag()/1000);
   }
  if(type_si[0]==13&&type_si[1]==13&&type_si[2]==11&&type_si[3]==11&&charge_si[0]!=charge_si[1]&&charge_si[2]!=charge_si[3]) 
   { 
   n_4leps_si++;
   a.SetPtEtaPhiE(pt_si[0],eta_si[0],phi_si[0],E_si[0]);
   b.SetPtEtaPhiE(pt_si[1],eta_si[1],phi_si[1],E_si[1]);
   c.SetPtEtaPhiE(pt_si[2],eta_si[2],phi_si[2],E_si[2]);
   d.SetPtEtaPhiE(pt_si[3],eta_si[3],phi_si[3],E_si[3]);
   h1->Fill((a+b+c+d).Mag()/1000);
   }
  }
 }   
//Background(ZZ* Bosons)
for (int i=0;i<mini_ba->GetEntries();i++) 
 {
 mini_ba->GetEntry(i);
 if(n_ba==4&&charge_ba[0]+charge_ba[1]+charge_ba[2]+charge_ba[3]==0)
  {
  if(type_ba[0]==11&&type_ba[1]==11&&type_ba[2]==11&&type_ba[3]==11)
   { 
   n_4leps_ba++;
   a.SetPtEtaPhiE(pt_ba[0],eta_ba[0],phi_ba[0],E_ba[0]);
   b.SetPtEtaPhiE(pt_ba[1],eta_ba[1],phi_ba[1],E_ba[1]);
   c.SetPtEtaPhiE(pt_ba[2],eta_ba[2],phi_ba[2],E_ba[2]);
   d.SetPtEtaPhiE(pt_ba[3],eta_ba[3],phi_ba[3],E_ba[3]);
   h2->Fill((a+b+c+d).Mag()/1000);
   }
  if(type_ba[0]==13&&type_ba[1]==13&&type_ba[2]==13&&type_ba[3]==13)
   { 
   n_4leps_ba++;
   a.SetPtEtaPhiE(pt_ba[0],eta_ba[0],phi_ba[0],E_ba[0]);
   b.SetPtEtaPhiE(pt_ba[1],eta_ba[1],phi_ba[1],E_ba[1]);
   c.SetPtEtaPhiE(pt_ba[2],eta_ba[2],phi_ba[2],E_ba[2]);
   d.SetPtEtaPhiE(pt_ba[3],eta_ba[3],phi_ba[3],E_ba[3]);
   h2->Fill((a+b+c+d).Mag()/1000);
   }
  if(type_ba[0]==11&&type_ba[1]==11&&type_ba[2]==13&&type_ba[3]==13&&charge_ba[0]!=charge_ba[1]&&charge_ba[2]!=charge_ba[3]) 
   { 
   n_4leps_ba++;
   a.SetPtEtaPhiE(pt_ba[0],eta_ba[0],phi_ba[0],E_ba[0]);
   b.SetPtEtaPhiE(pt_ba[1],eta_ba[1],phi_ba[1],E_ba[1]);
   c.SetPtEtaPhiE(pt_ba[2],eta_ba[2],phi_ba[2],E_ba[2]);
   d.SetPtEtaPhiE(pt_ba[3],eta_ba[3],phi_ba[3],E_ba[3]);
   h2->Fill((a+b+c+d).Mag()/1000);
   }
  if(type_ba[0]==11&&type_ba[1]==13&&type_ba[2]==11&&type_ba[3]==13&&charge_ba[0]!=charge_ba[1]&&charge_ba[2]!=charge_ba[3]) 
   { 
   n_4leps_ba++;
   a.SetPtEtaPhiE(pt_ba[0],eta_ba[0],phi_ba[0],E_ba[0]);
   b.SetPtEtaPhiE(pt_ba[1],eta_ba[1],phi_ba[1],E_ba[1]);
   c.SetPtEtaPhiE(pt_ba[2],eta_ba[2],phi_ba[2],E_ba[2]);
   d.SetPtEtaPhiE(pt_ba[3],eta_ba[3],phi_ba[3],E_ba[3]);
   h2->Fill((a+b+c+d).Mag()/1000);
   }
  if(type_ba[0]==11&&type_ba[1]==13&&type_ba[2]==13&&type_ba[3]==11&&charge_ba[0]!=charge_ba[1]&&charge_ba[2]!=charge_ba[3]) 
   { 
   n_4leps_ba++;
   a.SetPtEtaPhiE(pt_ba[0],eta_ba[0],phi_ba[0],E_ba[0]);
   b.SetPtEtaPhiE(pt_ba[1],eta_ba[1],phi_ba[1],E_ba[1]);
   c.SetPtEtaPhiE(pt_ba[2],eta_ba[2],phi_ba[2],E_ba[2]);
   d.SetPtEtaPhiE(pt_ba[3],eta_ba[3],phi_ba[3],E_ba[3]);
   h2->Fill((a+b+c+d).Mag()/1000);
   }
  if(type_ba[0]==13&&type_ba[1]==11&&type_ba[2]==11&&type_ba[3]==13&&charge_ba[0]!=charge_ba[1]&&charge_ba[2]!=charge_ba[3]) 
   { 
   n_4leps_ba++;
   a.SetPtEtaPhiE(pt_ba[0],eta_ba[0],phi_ba[0],E_ba[0]);
   b.SetPtEtaPhiE(pt_ba[1],eta_ba[1],phi_ba[1],E_ba[1]);
   c.SetPtEtaPhiE(pt_ba[2],eta_ba[2],phi_ba[2],E_ba[2]);
   d.SetPtEtaPhiE(pt_ba[3],eta_ba[3],phi_ba[3],E_ba[3]);
   h2->Fill((a+b+c+d).Mag()/1000);
   }
  if(type_ba[0]==13&&type_ba[1]==11&&type_ba[2]==13&&type_ba[3]==11&&charge_ba[0]!=charge_ba[1]&&charge_ba[2]!=charge_ba[3]) 
   { 
   n_4leps_ba++;
   a.SetPtEtaPhiE(pt_ba[0],eta_ba[0],phi_ba[0],E_ba[0]);
   b.SetPtEtaPhiE(pt_ba[1],eta_ba[1],phi_ba[1],E_ba[1]);
   c.SetPtEtaPhiE(pt_ba[2],eta_ba[2],phi_ba[2],E_ba[2]);
   d.SetPtEtaPhiE(pt_ba[3],eta_ba[3],phi_ba[3],E_ba[3]);
   h2->Fill((a+b+c+d).Mag()/1000);
   }
  if(type_ba[0]==13&&type_ba[1]==13&&type_ba[2]==11&&type_ba[3]==11&&charge_ba[0]!=charge_ba[1]&&charge_ba[2]!=charge_ba[3]) 
   { 
   n_4leps_ba++;
   a.SetPtEtaPhiE(pt_ba[0],eta_ba[0],phi_ba[0],E_ba[0]);
   b.SetPtEtaPhiE(pt_ba[1],eta_ba[1],phi_ba[1],E_ba[1]);
   c.SetPtEtaPhiE(pt_ba[2],eta_ba[2],phi_ba[2],E_ba[2]);
   d.SetPtEtaPhiE(pt_ba[3],eta_ba[3],phi_ba[3],E_ba[3]);
   h2->Fill((a+b+c+d).Mag()/1000);
   }
  }
 }   
//Background (ZZ* Bosons) ->trying to separate onshell Z mass and offshell Z mass
float mass[4][4];
float max_mass=0;
float mass_onshell;
float mass_offshell;
for (int i=0;i<mini_ba->GetEntries();i++) 
 {
 mini_ba->GetEntry(i);
 if(n_ba==4&&charge_ba[0]+charge_ba[1]+charge_ba[2]+charge_ba[3]==0)
  {
  a.SetPtEtaPhiE(pt_ba[0],eta_ba[0],phi_ba[0],E_ba[0]);  //a=0,b=1,c=2,d=3
  b.SetPtEtaPhiE(pt_ba[1],eta_ba[1],phi_ba[1],E_ba[1]);
  c.SetPtEtaPhiE(pt_ba[2],eta_ba[2],phi_ba[2],E_ba[2]);
  d.SetPtEtaPhiE(pt_ba[3],eta_ba[3],phi_ba[3],E_ba[3]);
  mass[0][1]=(a+b).Mag()/1000;
  mass[0][2]=(a+c).Mag()/1000;
  mass[0][3]=(a+d).Mag()/1000;
  mass[1][2]=(b+c).Mag()/1000;
  mass[1][3]=(b+d).Mag()/1000;
  mass[2][3]=(c+d).Mag()/1000;
  for(int j=0;j<3;j++)
   {
     for(int k=3;k>j;k--)
     {
      if(mass[j][k]>max_mass) max_mass=mass[j][k];
     }
   }
 mass_onshell=max_mass; 
   if(max_mass==mass[0][1]) mass_offshell=mass[2][3];
   if(max_mass==mass[0][2]) mass_offshell=mass[1][3]; 
   if(max_mass==mass[0][3]) mass_offshell=mass[1][2]; 
   if(max_mass==mass[1][2]) mass_offshell=mass[0][3]; 
   if(max_mass==mass[1][3]) mass_offshell=mass[0][2]; 
   if(max_mass==mass[2][3]) mass_offshell=mass[0][1]; 
  }
 }   
cout<<"Numbers of 4leptons events(Signal) that satisfies the event selection= "<<n_4leps_si<<endl;
cout<<"Numbers of 4leptons events(Background) that satisfies the event selections "<<n_4leps_ba<<endl;
//Normalization (8 TeV)
//Signal:
float cross_section_si=33.3E+03; //33.3pb
float efficieny_si=0.19822;  //19.922%
float total_intergrated_luminosity_si=1;  //1fb^-1
float Br_ZZ=0.02619;//Branching Ratio (H->ZZ*) M=125.0GeV
float Br_ll=0.033658;//Branching Ratio (Z->l+l-)
float N_si=cross_section_si*efficieny_si*total_intergrated_luminosity_si*Br_ZZ*Br_ll*Br_ll; //Normalization constant
cout<<"Normaliztion Constant for signal= "<<N_si<<endl;
double integral1;
integral1=h1->Integral();
h1->Scale(1/integral1);
h1->Scale(N_si);
h1->SetLineColor(2);
//Background:
float cross_section_ba=7.3E+03;
float efficieny_ba=0.011712;
float total_intergrated_luminosity_ba=1; 
float N_ba=cross_section_ba*efficieny_ba*total_intergrated_luminosity_ba; 
cout<<"Normaliztion Constant for background= "<<N_ba<<endl;
double integral2;
integral2=h2->Integral();
h2->Scale(1/integral2);
h2->Scale(N_si);
h2->SetLineColor(4); 


//Drawing Histograms
h1->GetXaxis()->SetTitle("M4l [GeV]");
h1->GetYaxis()->SetTitle("Entries/1 GeV");
h1->Draw();
h2->Draw("sames");




}
