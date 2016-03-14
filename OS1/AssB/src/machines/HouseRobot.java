/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package machines;
import people.Housekeeper;
/**
 *
 * @author jeff
 */
public class HouseRobot implements Housekeeper

{
    int energyLevel;
    String name;
    public HouseRobot(String name, int energyLevel) {
      this.name = name;
      this.energyLevel = energyLevel;
    }
    public int getEnergyLevel(){return energyLevel;}
    public void setEnergyLevel(int energyLevel){this.energyLevel = energyLevel;}

    @Override
    public void wash() {
        this.setEnergyLevel(this.getEnergyLevel() - 10);
        System.out.println("After washing, House "+ this.name +" now has "+this.getEnergyLevel()+" energy level.");
    }

    @Override
    public void vaccumClean() {
        this.setEnergyLevel(this.getEnergyLevel() - 20);
        System.out.println("After washing, House "+ this.name +" now has "+this.getEnergyLevel()+" energy level.");
    }
    
}
