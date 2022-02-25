class Solution {
    
    public int compareVersion(String version1, String version2) {
        String[] parsedVersion1 = version1.split("\\.");
        String[] parsedVersion2 = version2.split("\\.");
        
        for(int i=0;i<Math.max(parsedVersion1.length,parsedVersion2.length);i++) {
            int v1 = 0, v2 = 0;
            if(i < parsedVersion1.length) v1 = Integer.parseInt(parsedVersion1[i]);
            if(i < parsedVersion2.length) v2 = Integer.parseInt(parsedVersion2[i]);
            
            if(v1 < v2) return -1;
            if(v1 > v2) return 1;
        }
        return 0;
    }
}
