package processbuilder;
import java.io.IOException;
import java.lang.management.ManagementFactory;
import static java.lang.management.ManagementFactory.getRuntimeMXBean;
import java.lang.management.OperatingSystemMXBean;
import java.lang.management.RuntimeMXBean;

/**
 *
 * @author jeff
 */
public class Assignment_F {
    
    public static void main(String[] args) throws IOException, InterruptedException {
        System.out.println("Program starting...");
        Runtime run = Runtime.getRuntime();
        System.out.println("Available processors : " + run.availableProcessors());
        
        OperatingSystemMXBean osBean = ManagementFactory.getOperatingSystemMXBean();
        System.out.println("Operating System infos :");
        System.out.println("Bean: " + osBean.toString());
        System.out.println("OS Name: " + osBean.getName());
        System.out.println("OS Version: " + osBean.getVersion());
        System.out.println("Architecture: " + osBean.getArch());
        
        RuntimeMXBean mxBean = getRuntimeMXBean();
        System.out.println("Java Virtual machine infos : ");
        System.out.println("VM name : " + mxBean.getVmName());
        System.out.println("VM vendor : " + mxBean.getVmVendor());
        System.out.println("VM Version : " + mxBean.getVmVersion());
        
        for (int i = 0; i < args.length; i++) {
            ProcessBuilder pb = new ProcessBuilder(args[i]);
            Process proc = pb.start();
            proc.waitFor();
        }
        
        
    }
}
