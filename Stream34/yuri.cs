using System.Collections.Generic;
using System;

public class Kata
{
    public static List<string> GetPINs(string observed){
        string[,] grid = InitializeGrid();
        List<string> allCombinations = new List<string>();
        List<string> listaStringa = new List<string>();
      
        allCombinations = CalculateCombinations(observed, grid, listaStringa);
        return allCombinations;
    }
  
    public static List<string> CalculateCombinations(string str, string[,] grid, List<string> listaStringa){
        if(str.Equals("")){
           return new List<string>();
        }
 
        char first = str[0];
        int[] numPos = GetNumberPosition(grid, first);
        int i = numPos[1];
        int j = numPos[0];
      
        List<string> risultato_ricorsione = new List<string>();
                
        if(grid[i,j+1] != null){
            risultato_ricorsione = CalculateCombinations(str.Substring(1, str.Length), grid,listaStringa);
            foreach(string rr in risultato_ricorsione){
                listaStringa.Add(grid[i,j+1] + rr);
            }           
        }
        if(grid[i,j-1] != null){
            risultato_ricorsione = CalculateCombinations(str.Substring(1, str.Length), grid,listaStringa);
            foreach(string rr in risultato_ricorsione){
                listaStringa.Add(grid[i,j-1] + rr);
            }   
        }
        if(grid[i+1,j] != null){
            risultato_ricorsione = CalculateCombinations(str.Substring(1, str.Length), grid,listaStringa);
            foreach(string rr in risultato_ricorsione){
                listaStringa.Add(grid[i+1,j] + rr);
            }   
        }
        if(grid[i-1,j] != null){
            risultato_ricorsione = CalculateCombinations(str.Substring(1, str.Length), grid,listaStringa);
            foreach(string rr in risultato_ricorsione){
                listaStringa.Add(grid[i-1,j] + rr);
            }   
        }
      
        risultato_ricorsione = CalculateCombinations(str.Substring(1, str.Length), grid,listaStringa);
        foreach(string rr in risultato_ricorsione){
            listaStringa.Add(grid[i,j] + rr);
        }   

        return listaStringa;
    }
  
    public static int[] GetNumberPosition(string[,] grid, char first){
      int[] pos = new int[2];
        for(int i=0; i<5; i++){
          for (int j=0; j<5; j++){
            if(grid[i,j] != null && grid[i,j].Equals(first)){
              pos[0] = j;
              pos[1] = i;
              return pos;
            }            
          }
        }
      
      return null;
    }
  
    public static string[,] InitializeGrid(){
        string[,] grid = new string[5,5];

        for(int i=0; i<5; i++){
          for (int j=0; j<5; j++){
            grid[i,j] = null;
          }
        }
        
        int num = 0;
        grid[4,2] = num.ToString();
        num++;
      
        for(int i=1; i<4; i++){
          for (int j=1; j<4; j++){
            grid[i,j] = num.ToString();
            num++;
          }
        }  
      
        return grid;
    }
}