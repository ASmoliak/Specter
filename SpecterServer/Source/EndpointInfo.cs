namespace SpecterServer.Source;

public class EndpointInfo
{
    public EndpointInfo(string uuid, string? userHostAddress, 
                        string? operatingSystem, string? machineName,
                        string? username, string? uptime)
    {
        Uuid = uuid;
        UserHostAddress = userHostAddress;
        OperatingSystem = operatingSystem;
        MachineName = machineName;
        Username = username;
        Uptime = uptime;
    }

    public string Uuid { get; }
    public string? UserHostAddress { get; }
    public string? OperatingSystem { get; }
    public string? MachineName { get; }
    public string? Username { get; }
    public string? Uptime { get; }
}