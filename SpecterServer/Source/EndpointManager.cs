namespace SpecterServer.Source
{
    public class EndpointManager
    {
        public delegate void EndpointUpdatedHandler(EndpointInfo endpoint);
        public event EndpointUpdatedHandler? OnEndpointUpdated;
        private readonly Dictionary<string, EndpointInfo> m_endpoints = new();

        public void AddOrUpdateEndpoint(EndpointInfo endpointInfo)
        {
            m_endpoints[endpointInfo.Uuid] = endpointInfo;

            OnEndpointUpdated?.Invoke(endpointInfo);
        }

        public EndpointInfo? FindEndpoint(string uuid)
        {
            m_endpoints.TryGetValue(uuid, out var endpointInfo);
            return endpointInfo;
        }
    }
}
