import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
public class DataBaseToJson {
   public static ResultSet RetrieveData() throws Exception {
      DriverManager.registerDriver(new com.mysql.jdbc.Driver());
      String mysqlUrl = "jdbc:mysql://localhost/sample_database";
      Connection con = DriverManager.getConnection(mysqlUrl, "root", "password");
      Statement stmt = con.createStatement();
      ResultSet rs = stmt.executeQuery("Select * from user_table");
      return rs;
   }
   public static void main(String args[]) throws Exception {
      JSONObject jsonObject = new JSONObject();
      JSONArray array = new JSONArray();
      ResultSet rs = RetrieveData();
      while(rs.next()) {
         JSONObject record = new JSONObject();
         record.put("user_id", rs.getInt("user_id"));
         record.put("name", rs.getString("name"));
         record.put("age", rs.getInt("age"));
         record.put("phone", rs.getString("phone"));
         array.add(record);
      }
      jsonObject.put("status_code", 200);
      jsonObject.put("data", array);
      System.out.println(array);
   }
}
